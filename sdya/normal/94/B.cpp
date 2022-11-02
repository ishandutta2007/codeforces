#include <iostream>
#include <cstdio>
using namespace std;

int g[6][6];

int main() {
	int n = 5;
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int x, y;
		cin >> x >> y;
		--x;
		--y;
		g[x][y] = g[y][x] = 1;
	}
	bool ok = false;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			for (int k = j + 1; k < n; ++k) {
				int cnt = g[i][j] + g[j][k] + g[k][i];
				if (cnt == 0 || cnt == 3) {
					ok = true;
				}
			}
		}
	}
	if (ok) {
		cout << "WIN";
	} else {
		cout << "FAIL";
	}
	return 0;
}