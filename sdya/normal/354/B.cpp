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

const int maxN = 50;
int n;
char s[maxN][maxN];
int *dp[maxN + maxN][maxN];
int *cntA[maxN + maxN], *cntB[maxN + maxN];
int bt[1 << 20];
int p[maxN + maxN][maxN][maxN];

int pos[maxN][maxN];

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int d[2][1 << 21];

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", &s[i]);
	}

	for (int i = 0; i <= 2 * (n - 1); ++i) {
		int len = (i < n ? (i + 1) : (2 * n - 1 - i));
		for (int j = 0; j < 26; ++j) {
			dp[i][j] = new int[1 << len];
		}
		cntA[i] = new int[1 << len];
		cntB[i] = new int[1 << len];
	}

	for (int i = 0; i < (1 << 20); ++i) {
		bt[i] = 0;
		for (int j = 0; j < 20; ++j) {
			if (i & (1 << j)) {
				bt[i] = j;
				break;
			}
		}
	}

	for (int i = 0; i <= 2 * (n - 1); ++i) {
		int len = (i < n ? (i + 1) : (2 * n - 1 - i));
		int sx = i, sy = 0;
		while (sx >= n) {
			--sx;
			++sy;
		}
		for (int j = 0; j < len; ++j, --sx, ++sy) {
			pos[sx][sy] = j;
		}
	}

	for (int i = 0; i <= 2 * (n - 1); ++i) {
		int len = (i < n ? (i + 1) : (2 * n - 1 - i));
		int sx = i, sy = 0;
		while (sx >= n) {
			--sx;
			++sy;
		}
		for (int j = 0; j < len; ++j, --sx, ++sy) {
			for (int k = 0; k < 26; ++k) {
				int x1 = sx + 1, y1 = sy;
				int x2 = sx, y2 = sy + 1;
				int mask = 0;
				if (isValid(x1, y1) && s[x1][y1] == 'a' + k) {
					mask |= (1 << pos[x1][y1]);
				}
				if (isValid(x2, y2) && s[x2][y2] == 'a' + k) {
					mask |= (1 << pos[x2][y2]);
				}
				p[i][j][k] = mask;
			}
		}
	}

	for (int i = 0; i <= 2 * (n - 1); ++i) {
		int len = (i < n ? (i + 1) : (2 * n - 1 - i));
		int sx = i, sy = 0;
		while (sx >= n) {
			--sx;
			++sy;
		}
		cntA[i][0] = cntB[i][0] = 0;
		for (int j = 1; j < (1 << len); ++j) {
			int index = bt[j];
			cntA[i][j] = cntA[i][j ^ (1 << index)] + (int)(s[sx - index][sy + index] == 'a');
			cntB[i][j] = cntB[i][j ^ (1 << index)] + (int)(s[sx - index][sy + index] == 'b');
		}
	}

	for (int i = 0; i <= 2 * (n - 1); ++i) {
		int len = (i < n ? (i + 1) : (2 * n - 1 - i));
		for (int k = 0; k < 26; ++k) {
			dp[i][k][0] = 0;
			for (int j = 1; j < (1 << len); ++j) {
				int index = bt[j];
				dp[i][k][j] = (dp[i][k][j ^ (1 << index)] | p[i][index][k]);
			}
		}
	}

	int u = 0, v = 1;
	d[u][1] = (s[n - 1][n - 1] == 'a' ? 1 : (s[n - 1][n - 1] == 'b' ? -1 : 0));
	d[u][0] = 1000000000;
	for (int step = 2 * (n - 1) - 1; step >= 0; --step, swap(u, v)) {
		int len = (step < n ? (step + 1) : (2 * n - 1 - step));
		int value = 1000000000;
		if (step % 2 == 1) {
			value = -value;
		}
		for (int i = 0; i < (1 << len); ++i) {
			d[v][i] = value;
		}
		for (int j = 0; j < 26; ++j) {
			for (int i = 0; i < (1 << len); ++i) {
				if (dp[step][j][i] == 0 || d[u][dp[step][j][i]] == -value || d[u][dp[step][j][i]] == value) {
					continue;
				}
				int cnt = cntA[step][i] - cntB[step][i];
				int score = cnt > 0 ? 1 : (cnt < 0 ? -1 : 0);
				if (step % 2 == 1) {
					d[v][i] = max(d[v][i], d[u][dp[step][j][i]] + score);
				} else {
					d[v][i] = min(d[v][i], d[u][dp[step][j][i]] + score);
				}
			}
		}
	}

	int res = d[u][1];
	//cerr << res << endl;
	if (res > 0) {
		printf("FIRST\n");
	} else if (res < 0) {
		printf("SECOND\n");
	} else {
		printf("DRAW\n");
	}

	//cerr << clock() << endl;

	return 0;
}