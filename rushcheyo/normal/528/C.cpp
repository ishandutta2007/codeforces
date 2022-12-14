#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;
int n, m, tot = 1, nxt[N], fst[N], to[N], deg[N];
vector<pair<int, int>> g;
bool vis[N];

void addedge(int u, int v) {
	nxt[++tot] = fst[u]; fst[u] = tot; to[tot] = v;
	nxt[++tot] = fst[v]; fst[v] = tot; to[tot] = u;
	++deg[u], ++deg[v];
}

void dfs(int u) {
	for (int &i = fst[u], v; i; i = nxt[i])
		if (!vis[i >> 1]) {
			vis[i >> 1] = true;
			dfs(v = to[i]);
			g.emplace_back(u, v);
		}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1, a, b; i <= m; ++i) {
		scanf("%d%d", &a, &b);
		addedge(a, b);
	}
	for (int i = 1, lst = -1; i <= n; ++i)
		if (deg[i] & 1) {
			if (~lst) ++m, addedge(lst, i), lst = -1;
			else lst = i;
		}
	if (m & 1) ++m, addedge(1, 1);
	dfs(1);
	printf("%d\n", m);
	for (int i = 0; i < (int)g.size(); ++i) {
		if (i % 2) swap(g[i].first, g[i].second);
		printf("%d %d\n", g[i].first, g[i].second);
	}
	return 0;
}