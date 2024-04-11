#include <bits/stdc++.h>
using namespace std;

int a[200010], low[200010], dfn[200010], scc[200010], ins[200010], TOT, ALL, val[200010];
vector <int> S, from[200010], G[200010];
queue <int> q;

void dfs(int x) {
	low[x] = dfn[x] = ++TOT, ins[x] = 1;
	S.push_back(x);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (!dfn[v]) dfs(v), low[x] = min(low[x], low[v]);
		else if (ins[v]) low[x] = min(low[x], dfn[v]);
	}
	if (dfn[x] != low[x]) return ;
	ALL++, val[ALL] = 0x3f3f3f3f;
	while (1) {
		int v = S.back(); S.pop_back(), ins[v] = 0;
		scc[v] = ALL, val[ALL] = min(val[ALL], a[v]);
		if (v == x) break;
	}
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		from[i].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		if (!dfn[i]) dfs(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j];
			if (scc[i] != scc[v]) G[scc[i]].push_back(scc[v]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= ALL; i++) {
		if (G[i].size() == 0) ans += val[i];
	}
	printf("%d\n", ans);
	return 0;
}