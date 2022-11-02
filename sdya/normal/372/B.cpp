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

const int maxN = 42;
int n, m, q;
char s[maxN][maxN];
int c[maxN][maxN];
int d[maxN][maxN][maxN];

int l[maxN][maxN], r[maxN][maxN];

int ans[maxN][maxN][maxN][maxN];

int calc(int x1, int y1, int x2, int y2) {
	if (ans[x1][y1][x2][y2] != -1) {
		return ans[x1][y1][x2][y2];
	}

	int res = 0;
	for (int x = x1; x <= x2; ++x) {
		for (int y = y1; y <= y2; ++y) {
			int a = max(x1, l[x][y]);
			int b = min(x2, r[x][y]);
			if (a > b) {
				continue;
			}
			res += (min(c[x][y], y2) - y + 1) * (x - a + 1) * (b - x + 1);
		}
	}
	/*for (int j = y1; j <= y2; ++j) {
		for (int l = x1; l <= x2; ++l) {
			for (int r = l; r <= x2; ++r) {
				if (d[l][r][j] >= j) {
					res += min(d[l][r][j], y2) - j + 1;
				}
			}
		}
	}*/
	return ans[x1][y1][x2][y2] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	memset(c, -1, sizeof(c));
	for (int i = 0; i < n; ++i) {
		for (int j = m - 1; j >= 0; --j) {
			if (s[i][j] == '0') {
				c[i][j] = max(j, c[i][j + 1]);
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			l[i][j] = n;
			r[i][j] = -1;
			if (c[i][j] < j) {
				continue;
			}

			l[i][j] = r[i][j] = i;

			for (int k = i - 1; k >= 0; --k) {
				if (c[k][j] > c[i][j]) {
					l[i][j] = k;
				} else {
					break;
				}
			}
			for (int k = i + 1; k < n; ++k) {
				if (c[k][j] >= c[i][j]) {
					r[i][j] = k;
				} else {
					break;
				}
			}
		}
	}
	/*memset(d, -1, sizeof(d));
	for (int l = 0; l < n; ++l) {
		for (int r = l; r < n; ++r) {
			for (int i = 0; i < m; ++i) {
				int bound = m - 1;
				for (int j = l; j <= r; ++j) {
					bound = min(bound, c[j][i]);
				}
				d[l][r][i] = bound;
			}
		}
	}*/

	memset(ans, -1, sizeof(ans));
	for (int i = 1; i <= q; ++i) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%d\n", calc(a - 1, b - 1, c - 1, d - 1));
	}


	return 0;
}