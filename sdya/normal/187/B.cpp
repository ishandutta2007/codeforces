#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 62;
const int inf = 1000000000;
int a[maxN][maxN];
int g[maxN][maxN][maxN];
int n, m, r;

int d[maxN][maxN][maxN];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &r);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			a[i][j] = inf;
		}
	}

	for (int t = 1; t <= m; ++t) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				scanf("%d", &g[t][i][j]);
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				for (int k = 1; k <= n; ++k) {
					g[t][j][k] = min(g[t][j][k], g[t][j][i] + g[t][i][k]);
				}
			}
		}

		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				a[i][j] = min(a[i][j], g[t][i][j]);
			}
		}
	}

	for (int i = 0; i < maxN; ++i) {
		for (int j = 0; j < maxN; ++j) {
			for (int k = 0; k < maxN; ++k) {
				d[i][j][k] = inf;
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			d[i][0][j] = a[i][j];
		}
		for (int j = 0; j + 1 < maxN; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (d[i][j][k] == inf) {
					continue;
				}

				for (int l = 1; l <= n; ++l) {
					d[i][j + 1][l] = min(d[i][j + 1][l], d[i][j][k] + a[k][l]);
				}
			}
		}
	}

	for (int i = 1; i <= r; ++i) {
		int s, t, k;
		scanf("%d%d%d", &s, &t, &k);
		int res = inf;
		for (int j = 0; j <= k && j < maxN; ++j) {
			res = min(res, d[s][j][t]);
		}
		printf("%d\n", res);
	}


	return 0;
}