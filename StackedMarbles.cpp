#include <iostream>

using namespace std;

double weight(int row, int col){
	if(row == 1){
		return 0;
	}else if(col == 1){
		return weight(row-1, 1)/2 + 100;
	}else if(col == row){
		return weight(row-1, col-1)/2 + 100;
	}else{
		return weight(row-1, col-1)/2 + 100 + weight(row-1, col)/2 + 100;
	}
}

double weightFast(int row, int col, double history[100][100]){
	
	if(row == 1){
		return 0;
	}else if(col == 1){
		if(history[row-1][1]!=0){
			return history[row-1][1]/2 + 100;
		}else{
			double output =  weightFast(row-1, 1, history);
			history[row-1][1] = output;
			return output/2 + 100;
		}
	}else if(col == row){
		if(history[row-1][col-1]!= 0){
			return history[row-1][col-1]/2 + 100;
		}else{
			double output = weightFast(row-1, col-1, history);
			history[row-1][col-1] = output;
			return output/2 + 100;
		}
	}else{
		if(history[row-1][col-1]!=0 && history[row-1][col]){
			return history[row-1][col-1]/2 + 100 + history[row-1][col]/2 + 100;
		}else{
			double output1 = weightFast(row-1, col-1, history);
			double output2 = weightFast(row-1, col, history);
			history[row-1][col-1] = output1;
			history[row-1][col] = output2;
			return output1/2 + 100 + output2/2 + 100;
		}
	}
}

int main(){
	std::clock_t start;
	double history[100][100] = {};

	cout << "Running Test Cases..." << endl;
	cout << weight(1,1) << endl;
	cout << endl;
	cout << weight(2,1) << endl;
	cout << weight(2,2) << endl;
	cout << endl;
	cout << weight(3,1) << endl;
	cout << weight(3,2) << endl;
	cout << weight(3,3) << endl;
	cout << endl;
	cout << weight(4,1) << endl;
	cout << weight(4,2) << endl;
	cout << weight(4,3) << endl;
	cout << weight(4,4) << endl;
	cout << endl;
	start = std::clock();
	cout << weight(30,45) << endl;
	cout << "time: " << std::clock() - start;
	cout << endl;
	cout << weightFast(1,1, history) << endl;
	cout << endl;
	cout << weightFast(2,1, history) << endl;
	cout << weightFast(2,2, history) << endl;
	cout << endl;
	cout << weightFast(3,1, history) << endl;
	cout << weightFast(3,2, history) << endl;
	cout << weightFast(3,3, history) << endl;
	cout << endl;
	cout << weightFast(4,1, history) << endl;
	cout << weightFast(4,2, history) << endl;
	cout << weightFast(4,3, history) << endl;
	cout << weightFast(4,4, history) << endl;
	cout << endl;
	start = std::clock();
	cout << weightFast(30,45, history) << endl;
	cout << "time: " << std::clock() - start;
	cout << endl;

	return 0;
}