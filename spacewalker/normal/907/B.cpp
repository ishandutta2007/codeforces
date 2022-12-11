#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
	vector<vector<char>> grid(9, vector<char>(9, 0));
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 3; ++j) {
			string temp; cin >> temp;
			for (int k = 0; k < 3; ++k) {
				grid[i][3*j + k] = temp[k];
			}
		}
		if (i == 2 || i == 5) {
			cin.ignore(); cin.ignore();
		}
	}
	int x, y; cin >> x >> y; --x; --y;
	int telex = (x % 3);
	int teley = (y % 3);
	bool wasFilled = false;
	for (int i = 3 * telex; i < 3 * (telex + 1); ++i) {
		for (int j = 3*(teley); j < 3 * (teley + 1); ++j) {
			if (grid[i][j] == '.') {
				wasFilled = true;
				grid[i][j] = '!';
			}
		}
	}
	if (!wasFilled) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (grid[i][j] == '.') {
					grid[i][j] = '!';
				}
			}
		}
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << grid[i][j];
			if (j % 3 == 2 && j < 8) {
				cout << " ";
			}
		}
		cout << endl;
		if (i % 3 == 2) {
			cout << endl;
		}
	}
	return 0;
}