#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int grid[n][m];
	vector<int> row;
	vector<int> col;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
		}
	}

	int small;
	if (m > n) {
		for (int i = 0; i < n; i++) {
			small = 600;
			for (int j = 0; j < m; j++) {
				small = min(small, grid[i][j]);
			}
			for (int j = 0; j < m; j++) {
				grid[i][j]-=small;
			}
			for (int j = 0; j < small; j++) {
				row.push_back(i+1);
			}
		}

		for (int i = 0; i < m; i++) {
			small = 600;
			for (int j = 0; j < n; j++) {
				small = min(small, grid[j][i]);
			}
			for (int j = 0; j < n; j++) {
				grid[j][i]-=small;
			}
			for (int j = 0; j < small; j++) {
				col.push_back(i+1);
			}
		}
	}

	else {
		for (int i = 0; i < m; i++) {
				small = 600;
				for (int j = 0; j < n; j++) {
				small = min(small, grid[j][i]);
				}
				for (int j = 0; j < n; j++) {
					grid[j][i]-=small;
				}
				for (int j = 0; j < small; j++) {
					col.push_back(i+1);
				}
		}
		for (int i = 0; i < n; i++) {
			small = 600;
			for (int j = 0; j < m; j++) {
				small = min(small, grid[i][j]);
			}
			for (int j = 0; j < m; j++) {
				grid[i][j]-=small;
			}
			for (int j = 0; j < small; j++) {
				row.push_back(i+1);
			}
		}

	}
	
	bool ok = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] > 0) ok = false;
		}
	}
	if (!ok) {
		cout << -1 << endl;
	}
	else {
		cout << row.size() + col.size() << endl;
		for (int i = 0; i < row.size(); i++) {
			cout << "row " << row[i] << endl;
		}
		for (int i = 0; i < col.size(); i++) {
			cout << "col " << col[i] << endl;
		}
	}
	// cin >> n;
}