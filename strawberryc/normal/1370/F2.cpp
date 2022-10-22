#include <bits/stdc++.h>

typedef std::pair<int, int> pi;

const int N = 1005, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], dep[N], md, fa[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	if ((dep[u] = dep[fa[u] = fu] + 1) > md) md = dep[u];
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u);
}

pi query(std::vector<int> a)
{
	printf("? %d ", a.size());
	for (int i = 0; i < a.size(); i++) printf("%d ", a[i]);
	puts(""); fflush(stdout); int x, y; scanf("%d%d", &x, &y);
	return std::make_pair(x, y);
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int x, y; ecnt = md = 0;
		for (int i = 1; i <= n; i++) adj[i] = 0;
		scanf("%d", &n);
		for (int i = 1; i < n; i++) scanf("%d%d", &x, &y), add_edge(x, y);
		std::vector<int> que;
		for (int i = 1; i <= n; i++) que.push_back(i);
		pi pt = query(que); int dis = pt.second, rt = pt.first;
		dfs(rt, 0);
		int l = dis + 3 >> 1, r = std::min(dis + 1, md), u;
		while (l <= r)
		{
			int mid = l + r >> 1;
			que.clear();
			for (int i = 1; i <= n; i++) if (dep[i] >= mid) que.push_back(i);
			pt = query(que);
			if (pt.second == dis) u = pt.first, l = mid + 1;
			else r = mid - 1;
		}
		if (r - 1 == dis)
		{
			printf("! %d %d\n", u, rt); fflush(stdout);
			scanf("%*s"); continue;
		}
		int pu = u;
		for (int i = 1; i <= (r - 1 << 1) - dis; i++) pu = fa[pu];
		que.clear();
		for (int i = 1; i <= n; i++) if (dep[i] == dis - r + 2 && i != pu)
			que.push_back(i);
		printf("! %d %d\n", u, query(que).first); fflush(stdout);
		scanf("%*s");
	}
	return 0;
}