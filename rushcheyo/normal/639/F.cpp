#include <bits/stdc++.h>
using namespace std;

const int N = 600005;
int n, m, q, k, a[N], b[N], dfs_clock, st[N], ed[N], dfn[N], low[N], fa[N][19], dep[N], bel[N], bcc[N], _bcc[N];
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
void get_bcc(int *bcc, int u) {
	bcc[u] = k;
	for (int e : g[u])
		if (!bridge[e]) {
			int v = a[e] + b[e] - u;
			if (!bcc[v]) get_bcc(bcc, v);
		}
}
void dfs(int u) {
	st[u] = ++dfs_clock;
	for (int j = 1; 1 << j <= dep[u]; ++j)
		fa[u][j] = fa[fa[u][j - 1]][j - 1];
	for (int v : _g[u])
		if (v != fa[u][0]) {
			fa[v][0] = u;
			bel[v] = bel[u];
			dep[v] = dep[u] + 1;
			dfs(v);
		}
	ed[u] = dfs_clock;
}
int get_lca(int u, int v) {
	if (dep[u] < dep[v])
		swap(u, v);
	for (int j = 18; j >= 0; --j)
		if (fa[u][j] && dep[fa[u][j]] >= dep[v])
			u = fa[u][j];
	if (u == v) return u;
	for (int j = 18; j >= 0; --j)
		if (fa[u][j] != fa[v][j])
			u = fa[u][j], v = fa[v][j];
	return fa[u][0];
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
		if (!bcc[i]) ++k, get_bcc(bcc, i);
	for (int i = 1; i <= m; ++i)
		if (bcc[a[i]] != bcc[b[i]]) {
			_g[bcc[a[i]]].push_back(bcc[b[i]]);
			_g[bcc[b[i]]].push_back(bcc[a[i]]);
		}
	dfs_clock = 0;
	for (int i = 1; i <= k; ++i)
		if (!fa[i][0]) bel[i] = i, dfs(i);
	int R = 0;
	for (int cse = 1; cse <= q; ++cse) {
		vector<int> v, S;
		vector<pair<int, int>> e;
		int tmp1, tmp2;
		scanf("%d%d", &tmp1, &tmp2), v.resize(tmp1), e.resize(tmp2);;
		for (int i = 0; i < tmp1; ++i)
			scanf("%d", &v[i]), v[i] = bcc[(v[i] + R - 1) % n + 1], S.push_back(v[i]);
		for (int i = 0; i < tmp2; ++i) {
			scanf("%d%d", &e[i].first, &e[i].second);
			e[i].first = bcc[(e[i].first + R - 1) % n + 1];
			e[i].second = bcc[(e[i].second + R - 1) % n + 1];
			S.push_back(e[i].first), S.push_back(e[i].second);
		}
		auto cmp = [&](int x, int y) { return st[x] < st[y]; };
		sort(S.begin(), S.end(), cmp);
		S.erase(unique(S.begin(), S.end()), S.end());
		for (int i = 1, sz = (int)S.size(); i < sz; ++i)
			S.push_back(get_lca(S[i], S[i - 1]));
		sort(S.begin(), S.end(), cmp);
		S.erase(unique(S.begin(), S.end()), S.end());
		for (int x : S) g[x].clear(), dfn[x] = _bcc[x] = 0;
		m = 0;
		static int stk[N];
		int top = 0;
		for (int x : S) {
			while (top && st[x] > ed[stk[top]]) --top;
			if (top) {
				a[++m] = x, b[m] = stk[top];
				g[x].push_back(m), g[stk[top]].push_back(m);
			}
			stk[++top] = x;
		}
		for (const auto &p : e) {
			a[++m] = p.first, b[m] = p.second;
			g[p.first].push_back(m), g[p.second].push_back(m);
		}
		for (int i = 1; i <= m; ++i) bridge[i] = false;
		dfs_clock = 0;
		for (int x : S)
			if (!dfn[x]) dfs(x, 0);
		k = 0;
		for (int x : S)
			if (!_bcc[x]) ++k, get_bcc(_bcc, x);
		bool flag = true;
		for (int i = 1; i < (int)v.size(); ++i)
			flag &= _bcc[v[i]] == _bcc[v[0]];
		if (flag) puts("YES"), R = (R + cse) % n;
		else puts("NO");
	}
	return 0;
}