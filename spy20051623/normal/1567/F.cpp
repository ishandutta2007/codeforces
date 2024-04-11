#include <bits/stdc++.h>

using namespace std;

const int dir[4][2] = {-1, 0, 0, 1, 1, 0, 0, -1};

char s[505][505];
int c[505][505];
int r[505][505];

void op(int x, int y, int k) {
	r[x][y] = k;
	for (auto i : dir) {
		int xx = x + i[0], yy = y + i[1];
		if (s[xx][yy] != 'X') continue;
		if (c[xx][yy] == 2) {
			for (auto j : dir) {
				int xxx = xx + j[0], yyy = yy + j[1];
				if (s[xxx][yyy] == '.' && !r[xxx][yyy]) op(xxx, yyy, k == 1 ? 4 : 1);
			}
		} else {
			for (auto j : dir) {
				int xxx = xx + j[0], yyy = yy + j[1];
				if (r[xxx][yyy]) continue;
				if (x + xxx == xx + xx && y + yyy == yy + yy) op(xxx, yyy, k);
				else op(xxx, yyy, k == 1 ? 4 : 1);
			}
		}
	}
}

int main() {
//	freopen("in.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s[i] + 1);
	}
	for (int i = 2; i <= n - 1; ++i) {
		for (int j = 2; j <= m - 1; ++j) {
			if (s[i][j] == 'X') {
				for (auto k : dir) {
					if (s[i + k[0]][j + k[1]] == '.') ++c[i][j];
				}
				if (c[i][j] & 1) {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (s[i][j] == 'X') r[i][j] = c[i][j] / 2 * 5;
			else if (!r[i][j]) {
				for (auto k : dir) {
					if (c[i + k[0]][j + k[1]] == 2) op(i, j, 1);
				}
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (!r[i][j] && s[i][j] == '.') {
				op(i, j, 1);
			}
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%d ", r[i][j]);
		}
		printf("\n");
	}
	return 0;
}//