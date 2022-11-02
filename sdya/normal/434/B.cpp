#define _CRT_SECURE_NO_WARNINGS
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
#include <stack>
#include <ctime>
#include <unordered_map>
#include <unordered_set>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
int n, m, q;
int a[maxN][maxN], b[maxN][maxN], c[maxN][maxN];

int mode[maxN], x[maxN], y[maxN];
int res[maxN];

int d[4][maxN][maxN];

void calcRow(int x) {
	for (int j = m - 1; j >= 0; --j) {
		if (a[x][j] == 0) {
			d[0][x][j] = 0;
			continue;
		}
		d[0][x][j] = 1;
		if (j + 1 < m) {
			d[0][x][j] += d[0][x][j + 1];
		}
	}

	for (int j = 0; j < m; ++j) {
		if (a[x][j] == 0) {
			d[1][x][j] = 0;
			continue;
		}
		d[1][x][j] = 1;
		if (j - 1 >= 0) {
			d[1][x][j] += d[1][x][j - 1];
		}
	}
}

void calcColumn(int y) {
	for (int i = n - 1; i >= 0; --i) {
		if (a[i][y] == 0) {
			d[2][i][y] = 0;
			continue;
		}
		d[2][i][y] = 1;
		if (i + 1 < n) {
			d[2][i][y] += d[2][i + 1][y];
		}
	}

	for (int i = 0; i < n; ++i) {
		if (a[i][y] == 0) {
			d[3][i][y] = 0;
			continue;
		}
		d[3][i][y] = 1;
		if (i - 1 >= 0) {
			d[3][i][y] += d[3][i - 1][y];
		}
	}
}

int p[maxN], s[maxN];

int calculate(int x, int n) {
	for (int j = x - 1; j >= 0; --j) {
		p[j] = min(p[j + 1], p[j]);
	}
	for (int j = x + 1; j < n; ++j) {
		p[j] = min(p[j - 1], p[j]);
	}

	int index = x;
	int res = 0;
	for (int j = x; j >= 0; --j) {
		int len = p[j];

		while (index < n && p[index] >= len) {
			++index;
		}

		int h = len;
		int w = index - j;
		res = max(res, h * w);
	}
	return res;
}

void solve() {
	for (int i = 0; i < n; ++i) {
		calcRow(i);
	}
	for (int i = 0; i < m; ++i) {
		calcColumn(i);
	}

	for (int i = 0; i < q; ++i) {
		if (mode[i] == 1) {
			a[x[i]][y[i]] ^= 1;
			calcRow(x[i]);
			calcColumn(y[i]);
		} else {
			for (int k = 0; k < 4; ++k) {
				if (k < 2) {
					for (int j = 0; j < n; ++j) {
						p[j] = d[k][j][y[i]];
					}
				} else {
					for (int j = 0; j < m; ++j) {
						p[j] = d[k][x[i]][j];
					}
				}

				int nn = (k < 2 ? x[i] : y[i]);
				int mm = (k < 2 ? n : m);
				res[i] = max(res[i], calculate(nn, mm));
				reverse(p, p + mm);
				nn = mm - 1 - nn;
				res[i] = max(res[i], calculate(nn, mm));
			}
		}
	}

	for (int i = 0; i < q; ++i) {
		if (mode[i] == 1) {
			a[x[i]][y[i]] ^= 1;
		}
	}
}

int cres[maxN];

void trivial() {
	for (int i = 0; i < q; ++i) {
		if (mode[i] == 1) {
			a[x[i]][y[i]] ^= 1;
			continue;
		}

		int res = 0;
		for (int x1 = 0; x1 < n; ++x1) {
			for (int y1 = 0; y1 < m; ++y1) {
				for (int x2 = x1; x2 < n; ++x2) {
					for (int y2 = y1; y2 < m; ++y2) {
						if (((x1 == x[i] || x2 == x[i]) && y1 <= y[i] && y2 >= y[i])
							|| ((y1 == y[i] || y2 == y[i]) && x1 <= x[i] && x2 >= x[i]))
						{
							bool good = true;
							for (int u = x1; u <= x2 && good; ++u) {
								for (int v = y1; v <= y2 && good; ++v) {
									if (a[u][v] == 0) {
										good = false;
									}
								}
							}
							if (good) {
								res = max(res, (x2 - x1 + 1) * (y2 - y1 + 1));
							}
						}
					}
				}
			}
		}
		cres[i] = res;
	}

	for (int i = 0; i < q; ++i) {
		if (mode[i] == 1) {
			a[x[i]][y[i]] ^= 1;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int tests = 0;
	while (false) {
		++tests;
		cerr << tests << endl;
		memset(a, 0, sizeof(a));
		memset(d, 0, sizeof(d));
		n = rand() % 4 + 1;
		m = rand() % 4 + 1;
		q = rand() % 4 + 1;
		printf("%d %d %d\n", n, m, q);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				a[i][j] = rand() % 2;
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}

		for (int i = 0; i < q; ++i) {
			mode[i] = rand() % 2 + 1;
			x[i] = rand() % n;
			y[i] = rand() % m;
			res[i] = cres[i] = 0;
			printf("%d %d %d\n", mode[i], x[i] + 1, y[i] + 1);
		}

		trivial();
		solve();
		for (int i = 0; i < q; ++i) {
			if (res[i] != cres[i]) {
				solve();
				cerr << "BAD" << endl;
				return 0;
			}
		}
	}

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < q; ++i) {
		scanf("%d%d%d", &mode[i], &x[i], &y[i]);
		--x[i];
		--y[i];
	}

	//trivial();

	solve();

	for (int i = 0; i < q; ++i) {
		if (mode[i] == 2) {
			printf("%d\n", res[i]);
			/*if (res[i] != cres[i]) {
				cerr << "FUCK" << endl;
			}*/
		}
	}

	return 0;
}