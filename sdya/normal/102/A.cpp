#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 110;
int a[maxN];
bool g[maxN][maxN];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int res = 1000000000;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u][v] = g[v][u] = 1;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			for (int k = j + 1; k <= n; ++k) {
				if (g[i][j] && g[j][k] && g[i][k]) {
					res = min(res, a[i] + a[j] + a[k]);
				}
			}
		}
	}
	if (res == 1000000000) {
		res = -1;
	}
	cout << res << endl;
	return 0;
}