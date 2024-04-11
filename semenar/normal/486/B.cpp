#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define SP << " " <<
#define LINE std::cout << endl;
#define STOP system("pause")

using namespace std;

int a[100][100], b[100][100], new_b[100][100];
vector<int> rows;
vector<int> columns;

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		bool is_row = true;
		for (int j = 0; j < n; j++) {
			if (b[i][j] == 0) {
				is_row = false;
			}
		}
		if (is_row) {
			rows.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		bool is_column = true;
		for (int j = 0; j < m; j++) {
			if (b[j][i] == 0) {
				is_column = false;
			}
		}
		if (is_column) {
			columns.push_back(i);
		}
	}
	for (int i = 0; i < rows.size(); i++) {
		for (int j = 0; j < columns.size(); j++) {
			a[rows[i]][columns[j]] = 1;
		}
	}
	if (columns.size() > 0) {
		for (int i = 0; i < rows.size(); i++) {
			for (int j = 0; j < n; j++) {
				new_b[rows[i]][j] = 1;
			}
		}
	}
	if (rows.size() > 0) {
		for (int i = 0; i < columns.size(); i++) {
			for (int j = 0; j < m; j++) {
				new_b[j][columns[i]] = 1;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (b[i][j] != new_b[i][j]) {
				cout << "NO";
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << ' ';
		}
		LINE;
	}
	return 0;
}