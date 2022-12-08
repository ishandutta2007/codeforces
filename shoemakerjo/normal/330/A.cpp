#include <iostream>

using namespace std;

int main() {
	int r, c;
	cin >> r >> c;
	string cur;
	int nums[r][c]; //0 is strawberry 1 is good 2 is eaten already
	for (int i = 0; i < r; i++) {
		cin >> cur;
		for (int j = 0; j < c; j++) {
			if (cur[j]=='S') nums[i][j] = 0;
			else nums[i][j]= 1;
		}
	}
	int count = 0;
	for (int i = 0; i < r; i++) {
		bool ok = true;
		for (int j = 0; j < c; j++) {
			if (nums[i][j] == 0) ok = false;
		}
		if (ok) {
			for (int j = 0; j < c; j++) {
				if (nums[i][j]==1) {
					count++;
					nums[i][j] = 2;
				}
			}
			
		}
	}
	for (int i = 0; i < c; i++) {
		bool ok = true;
		for (int j = 0; j < r; j++) {
			if (nums[j][i] == 0) ok = false;
		}
		if (ok) {
			for (int j = 0; j < r; j++) {
				if (nums[j][i]==1) {
					count++;
					nums[j][i] = 2;
				}
			}
			
		}
	}
	cout << count << endl;
	// cin >> r;


}