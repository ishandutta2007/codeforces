#include <bits/stdc++.h>
using namespace std;

#define N 300300

int m, fa[N][22], dp[N];
int ca, cb, d, cnt[N], vis[N], T;

int anc(int x, int d) {
	if (!d) return x;
	for (int i = 31 - __builtin_clz(d); i >= 0; i --) if (d & (1 << i)) x = fa[x][i];
	return x;
}

int lca(int x, int y) {
	if (dp[x] > dp[y]) x = anc(x, dp[x] - dp[y]);
	else if (dp[y] > dp[x]) y = anc(y, dp[y] - dp[x]);
	if (x == y) return x;
	for (int i = 31 - __builtin_clz(dp[x]); i >= 0; i --) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

int dist(int x, int y) {
	int z = lca(x, y);
	return dp[x] - dp[z] + dp[y] - dp[z];
}

int go(int x, int y) {
	int z = lca(x, y);
	if (z == y) return anc(x, dp[x] - dp[y] - 1);
	return fa[y][0];
}

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d", &m);
	cnt[ca=1] = 1;
	for (int i = 1; i <= m; i ++) {
		int x = i + 1, p;
		scanf("%d", &p);
		fa[x][0] = p;
		for (int j = 1; j <= 20; j ++) fa[x][j] = fa[fa[x][j-1]][j-1];
		dp[x] = dp[p] + 1;
		if (ca && cb) {
			int da = dist(x, ca), db = dist(x, cb);
			if (da > db) swap(ca, cb), swap(da, db);
			if (da == (d + 1) / 2) {
				int y = go(x, ca);
				cnt[y] = 1;
				cnt[ca] = cnt[cb] + 1;
				T ++;
				vis[y] = vis[cb] = T;
				cb = 0;
				d ++;
			}
			else if (da == d / 2) cnt[ca] ++;
		}
		else {
			int da = dist(x, ca);
			if (da == d / 2 + 1) {
				cb = go(x, ca);
				cnt[ca] -= cnt[cb];
				cnt[cb] = 1;
				d ++;
			}
			else if (da == d / 2) {
				int y = go(x, ca);
				if (vis[y] != T) cnt[y] = 0, vis[y] = T;
				cnt[y] ++;
				cnt[ca] ++;
			}
		}
		printf("%d\n", cnt[ca] + cnt[cb]);
	}
	return 0;
}