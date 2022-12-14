#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int n, m, q, a[N], b[N], dfn[N], low[N], dfs_clock, k, bcc[N], fa[N][18], bel[N], dep[N], s[2][N];
bool bridge[N];
vector<int> g[N], _g[N];

void dfs(int u, int _fa) {
	low[u] = dfn[u] = ++dfs_clock;
	for (int e : g[u]) {
		if (e == _fa) continue;
		int v = a[e] + b[e] - u;
		if (!dfn[v]) {
			dfs(v, e);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfn[u])
				bridge[e] = true;
		} else
			low[u] = min(low[u], dfn[v]);
	}
}
void get_bcc(int u) {
	bcc[u] = k;
	for (int e : g[u])
		if (!bridge[e]) {
			int v = a[e] + b[e] - u;
			if (!bcc[v]) get_bcc(v);
		}
}
void dfs(int u) {
	for (int j = 1; 1 << j <= dep[u]; ++j)
		fa[u][j] = fa[fa[u][j - 1]][j - 1];
	for (int v : _g[u])
		if (v != fa[u][0]) {
			fa[v][0] = u;
			bel[v] = bel[u];
			dep[v] = dep[u] + 1;
			dfs(v);
		}
}
int get_lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v);
	for (int j = 17; j >= 0; --j)
		if (fa[u][j] && dep[fa[u][j]] >= dep[v])
			u = fa[u][j];
	if (u == v) return u;
	for (int j = 17; j >= 0; --j)
		if (fa[u][j] != fa[v][j])
			u = fa[u][j], v = fa[v][j];
	return fa[u][0];
}
void get_sum(int u) {
	for (int v : _g[u])
		if (v != fa[u][0])
			get_sum(v), s[0][u] += s[0][v], s[1][u] += s[1][v];
	if (fa[u][0] && s[0][u] && s[1][u]) {
		puts("No");
		exit(0);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", a + i, b + i);
		g[a[i]].push_back(i), g[b[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i)
		if (!dfn[i]) dfs(i, 0);
	for (int i = 1; i <= n; ++i)
		if (!bcc[i]) ++k, get_bcc(i);
	for (int i = 1; i <= m; ++i)
		if (bcc[a[i]] != bcc[b[i]]) {
			_g[bcc[a[i]]].push_back(bcc[b[i]]);
			_g[bcc[b[i]]].push_back(bcc[a[i]]);
		}
	for (int i = 1; i <= k; ++i)
		if (!fa[i][0]) bel[i] = i, dfs(i);
	for (int u, v; q--;) {
		scanf("%d%d", &u, &v);
		u = bcc[u], v = bcc[v];
		if (bel[u] != bel[v]) return puts("No"), 0;
		int t = get_lca(u, v);
		++s[0][u], --s[0][t];
		++s[1][v], --s[1][t];
	}
	for (int i = 1; i <= k; ++i)
		if (!fa[i][0]) get_sum(i);
	puts("Yes");
}