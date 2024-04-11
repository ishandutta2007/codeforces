#include <cstdio>
#include <iostream>

using namespace std;

typedef long long ll;

const int MAXN = 1010;
const int MAXT = 24;
const int BASE = 2;
const int MAXL = MAXN * MAXN * 4;

int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};

int dp[MAXN * MAXN * 4][MAXT];
int grid[MAXN][MAXN];
bool vis[MAXN * MAXN * 4];
int len[MAXN * MAXN * 4];
int tmp[MAXN * MAXN * 4];

int N, B;
int Q;

int conv(int x, int y, int d) {
	return y + MAXN * (x + MAXN * d);
}

void disp(int p) {
	int y = p % MAXN;
	p /= MAXN;
	int x = p % MAXN;
	int d = p / MAXN;
	printf("(%d %d), d = %d\n", x, y, d);
}

int main() {
	scanf("%d %d", &N, &B);
	for(int i = 0; i <= B; ++i) {
		for(int j = 0; j <= B; ++j) {
			grid[i][j] = -1;
		}
	}

	for(int i = 0; i < N; ++i) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a == c) {
			if (b < d) {
				for(int y = b; y <= d; ++y) {
					grid[a][y] = 0;
				}
			} else {
				for(int y = d; y <= b; ++y) {
					grid[a][y] = 2;
				}
			}
		} else {
			if (a < c) {
				for(int x = a; x <= c; ++x) {
					grid[x][b] = 1;
				}
			} else {
				for(int x = c; x <= a; ++x) {
					grid[x][b] = 3;
				}
			}
		}
	}

	for(int i = 0; i <= B; ++i) {
		for(int j = 0; j <= B; ++j) {
			for(int d = 0; d < 4; ++d) {
				int &ret = dp[conv(i, j, d)][0];
				int nx = i + mx[d];
				int ny = j + my[d];
				if (nx > B || ny > B || nx < 0 || ny < 0) {
					ret = -1;
				} else {
					int nd = d;
					if (grid[nx][ny] != -1) {
						nd = grid[nx][ny];
					}
					ret = conv(nx, ny, nd);
				}
			}
		}
	}

	for(int i = 0; i <= B; ++i) {
		for(int j = 0; j <= B; ++j) {
			for(int d = 0; d < 4; ++d) {
				int p = conv(i, j, d);
				if (vis[p]) continue;
				int cur = p;
				int cnt = 0;
				while (cur != -1 && !vis[cur]) {
					vis[cur] = true;
					tmp[cur] = cnt;
					++cnt;
					cur = dp[cur][0];
				}

				int cyc = -1;
				if (cur != -1) {
					if (len[cur]) cyc = len[cur];
					else cyc = cnt - tmp[cur];
				}

				cur = p;
				while (cur != -1 && !len[cur]) {
					len[cur] = cyc;
					cur = dp[cur][0];
				}
			}
		}
	}



	for(int t = 0; t + 1 < MAXT; ++t) {
		for(int i = 0; i <= B; ++i) {
			for(int j = 0; j <= B; ++j) {
				for(int d = 0; d < 4; ++d) {
					int p = conv(i, j, d);
					int nxt = p;
					for(int k = 0; k < BASE; ++k) {
						nxt = dp[nxt][t];
						if (nxt == -1) break;
					}
					dp[p][t + 1] = nxt;
				}
			}
		}
	}

	ll maxstep = 1;
	for(int i = 0; i < MAXT; ++i) maxstep *= BASE;

	scanf("%d", &Q);
	for(int q = 0; q < Q; ++q) {
		int a, b;
		char c;
		ll T;
		scanf("%d %d %c", &a, &b, &c);
		cin >> T;

		int dir;
		if (c == 'U') dir = 0;
		else if (c == 'R') dir = 1;
		else if (c == 'D') dir = 2;
		else if (c == 'L') dir = 3;
		if (grid[a][b] != -1) dir = grid[a][b];

		int p = conv(a, b, dir);
		if (len[p] != -1) {
			ll TT = (MAXL + len[p] - MAXL % len[p]) + (T % len[p]);
			if (T > TT) T = TT;
		}

		ll tt = maxstep;
		for(int t = MAXT - 1; t >= 0; --t) {
			tt /= BASE;
			while (dp[p][t] != -1 && tt <= T) {
				T -= tt;
				p = dp[p][t];
			}
		}

/*		for(int i = 0; i < T; ++i) {
			printf("time = %d\n", i);
			disp(p);
			int nxt = dp[p][0];
			if (nxt == -1) break;
			p = nxt;
		}*/

		int y = p % MAXN;
		p /= MAXN;
		int x = p % MAXN;
		printf("%d %d\n", x, y);
	}
	return 0;
}