#include <bits/stdc++.h>
using namespace std;
#define N 16

const int inf = 1e9;

int n, m, a, b, c, d[N][N], dis[N][N];
int ans, deg[N], cnt, x[N], vis[N];

bool disconnect() {
	if (!vis[1]) return 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++) dis[i][j] = d[i][j];
	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (vis[i] && vis[j] && dis[i][j] == inf) return 1;
	return 0;
}

int calc(int use, int last) {
	if (use == cnt) return 0;
	int rlt = inf;
	for (int i = last + 1; i <= cnt; i ++) if (!vis[i]) {
		for (int j = i + 1; j <= cnt; j ++) if (!vis[j]) {
			vis[i] = 1, vis[j] = 1;
			rlt = min(rlt, dis[x[i]][x[j]] + calc(use + 2, i));
			vis[i] = 0, vis[j] = 0;
		}
		break;
	}
	return rlt;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d %d", &n, &m);
	if (!m) {
		puts("0"); return 0;
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) if (i != j) d[i][j] = inf;
	}
	while (m --) {
		scanf("%d %d %d", &a, &b, &c);
		vis[a] = vis[b] = 1;
		ans += c;
		deg[a] ^= 1, deg[b] ^= 1;
		if (d[a][b] > c) d[a][b] = d[b][a] = c;
	}
	if (disconnect()) {
		puts("-1"); return 0;
	}
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i ++) {
		if (deg[i]) x[++cnt] = i;
	}
	printf("%d\n", ans + calc(0, 0));
	return 0;
}