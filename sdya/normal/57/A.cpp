#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <bitset>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	vector < int > x, y;
	x.push_back(x1);
	y.push_back(y1);
	x.push_back(x2);
	y.push_back(y2);
	for (int i = 0; i <= n; i += n) {
		for (int j = 0; j <= n; j += n) {
			x.push_back(i);
			y.push_back(j);
		}
	}
	int m = x.size();
	vector < vector < int > > g(m, vector < int > (m, 1000000));
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			if (x[i] == x[j] && (x[i] == 0 || x[i] == n)) {
				g[i][j] = abs(y[i] - y[j]);
			}
			if (y[i] == y[j] && (y[i] == 0 || y[i] == n)) {
				g[i][j] = abs(x[i] - x[j]);
			}
		}
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < m; ++k) {
				g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
			}
		}
	}

	cout << g[0][1] << endl;

	return 0;
}