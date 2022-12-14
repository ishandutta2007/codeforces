#include <bits/stdc++.h>
using namespace std;

#define N 99
#define INF 1e9

int n, k, m, dis[N][N], a, b, c, f[N][N][N];

void calc(int a, int b, int c) {
	if (c == 1) {
		f[a][b][c] = 0;
		return;
	}
	if (c > abs(a - b) + 1) {
		f[a][b][c] = INF;
		return;
	}
	f[a][b][c] = INF;
    if (a > b) {
		for (int d = b; d < a; d ++) f[a][b][c] = min(f[a][b][c], dis[a][d] + min(f[d][b][c-1], f[d][a-1][c-1]));
    }
    else {
		for (int d = b; d > a; d --) f[a][b][c] = min(f[a][b][c], dis[a][d] + min(f[d][b][c-1], f[d][a+1][c-1]));
    }
}

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) {
		if (i == j) dis[i][j] = 0;
		else dis[i][j] = INF;
	}
	scanf("%d", &m);
	while (m --) {
		scanf("%d %d %d", &a, &b, &c);
		dis[a][b] = min(dis[a][b], c);
	}
	if (k > n) {
		puts("-1");
		return 0;
	}
    if (k == 1) {
		puts("0");
		return 0;
    }
    if (k == 2) {
		int ans = INF;
		for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (i != j) ans = min(ans, dis[i][j]);
		if (ans == INF) puts("-1");
		else printf("%d\n", ans);
		return 0;
    }
	for (c = 1; c <= k; c ++) for (a = 1; a <= n; a ++) for (b = 1; b <= n; b ++) {
		calc(a, b, c);
	}
	int ans = INF;
	for (int i = 1; i <= n; i ++) ans = min(ans, min(f[i][n][k], f[i][1][k]));
	if (ans == INF) puts("-1");
	else printf("%d\n", ans);
	return 0;
}