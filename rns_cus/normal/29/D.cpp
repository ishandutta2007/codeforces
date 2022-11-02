#include <bits/stdc++.h>
using namespace std;

#define N 1010
#define M 11

int n, k, cnt, prt[N], c[N], fa[N][M], dp[N], x[N];
bool vis[N], flag[N][N];
vector <int> v[N];

void dfs(int x) {
    vis[x] = 1;
    for (int i = 0; i < v[x].size(); i ++) {
		int y = v[x][i];
		if (!vis[y]) fa[y][0] = x, dp[y] = dp[x] + 1, dfs(y);
    }
}

void prepare() {
	dfs(1);
	int Log = log2(n);
	for (int j = 1; j <= Log; j ++) {
		for (int i = 1; i <= n; i ++) if (dp[i] >= (1 << j)) {
			fa[i][j] = fa[fa[i][j-1]][j-1];
		}
	}
}

int ANC(int x, int d) {
	int Log = log2(d);
	for (int i = Log; i >= 0; i --) {
		if (d >= (1 << i)) x = fa[x][i], d -= (1 << i);
	}
	return x;
}

int LCA(int x, int y) {
	int dx = dp[x], dy = dp[y];
	x = ANC(x, dx - dy);
	y = ANC(y, dy - dx);
	if (x == y) return x;
	int Log = log2(dp[x]);
	for (int i = Log; i >= 0; i --) {
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	}
	return fa[x][0];
}

bool go(int x, int y) {
	int z = LCA(x, y);
	prt[++cnt] = x;
	while (x != z) {
		int xx = fa[x][0];
		if (flag[x][xx]) return 0;
		flag[x][xx] = 1;
		prt[++cnt] = xx;
		x = xx;
	}
	int runs = 0;
	c[runs++] = y;
	while (y != z) {
		int yy = fa[y][0];
		if (flag[yy][y]) return 0;
		flag[yy][y] = 1;
		c[runs++] = yy;
		y = yy;
	}
	reverse(c, c + runs);
	for (int i = 1; i < runs; i ++) prt[++cnt] = c[i];
	cnt --;
	return 1;
}

bool route() {
	for (int i = 0; i <= k; i ++) {
		if (!go(x[i], x[i+1])) return 0;
	}
	prt[++cnt] = 1;
	return 1;
}

int main() {
//	freopen("d.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i ++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b), v[b].push_back(a);
	}
	for (int i = 2; i <= n; i ++) k += (v[i].size() == 1);
	for (int i = 1; i <= k; i ++) scanf("%d", &x[i]);
	x[0] = x[k+1] = 1;
	prepare();
	if (!route()) puts("-1");
	else {
		for (int i = 1; i <= cnt; i ++) printf("%d ", prt[i]);
		puts("");
	}
	return 0;
}