#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
int main() {
	int n, m;
	cin >> n >> m;
	char tmp;
	vector<vector<int>>a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tmp;
			if (tmp == 'W') {
				a[i][j] = 0;
			}
			else {
				a[i][j] = 1;
			}
		}
	}
	int z = 0;
	int i1 = 0;
	int j1 = 0;
	int y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				i1 = i;
				j1 = j;
				y = 1;
				break;
			}
		}
		if (y == 1) {
			break;
		}
	}
	int j2 = -1;
	for (int j = j1; j < m; j++) {
		if (a[i1][j] == 1) {
			j2 = j;
		}
	}
	cout << (i1 + i1 + j2 - j1) / 2  + 1 << " " << (j1 + j2) / 2 + 1;
	return 0;
}