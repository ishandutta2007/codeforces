/// Choe Kwang B

#include <bits/stdc++.h>
using namespace std;
#define N 101
#define inf 1000000000

int n, k, m, f[N][N][N];
bool vis[N][N];

int bad(int i, int j, int m) {
	for (int r = j; r <= m; r ++) if (vis[i][r]) return r;
	return 0;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &k);
	int midx = k / 2 + 1, midy = midx;
	for (int i = 1; i <= k; i ++) {
		for (int j = 1; j <= k; j ++) {
			for (int m = j; m <= k; m ++) f[i][j][m] = f[i][j][m-1] + abs(midx - i) + abs(midy - m);
		}
	}
	while (n --) {
		scanf("%d", &m);
		int ans = inf, x, st;
		for (int i = 1; i <= k; i ++) {
			for (int j = 1; j <= k - m + 1; j ++) if (f[i][j][j+m-1] < ans) {
				int J = bad(i, j, j + m - 1);
				if (J) j = J;
				else ans = f[i][j][j+m-1], x = i, st = j;
			}
		}
		if (ans == inf) puts("-1");
		else {
			printf("%d %d %d\n", x, st, st + m - 1);
			for (int j = st; j < st + m; j ++) vis[x][j] = 1;
		}
	}
	return 0;
}