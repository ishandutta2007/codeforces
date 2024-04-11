#include <bits/stdc++.h>

const int N = 1005, M = N << 1;

int n, now = 1, ecnt, nxt[M], adj[N], go[M], sze[N], ms[N], G = 1, tot, dep[N], ans;

std::vector<int> sbt[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	sze[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u), sze[u] += sze[v],
			ms[u] = std::max(ms[u], sze[v]);
}

void dfs2(int u, int fu)
{
	dep[u] = dep[fu] + 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs2(v, u);
}

void dfs3(int u, int fu, int i)
{
	sbt[i].push_back(u);
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs3(v, u, i);
}

int main()
{
	int x, y;
	std::cin >> n;
	for (int i = 1; i < n; i++)
		scanf("%d%d", &x, &y), add_edge(x, y);
	dfs(1, 0);
	for (int u = 1; u <= n; u++)
		if (std::max(ms[u], n - sze[u]) < std::max(ms[G], n - sze[G]))
			G = u;
	ans = G; dfs2(G, 0);
	for (int e = adj[G], v = go[e]; e; e = nxt[e], v = go[e])
		dfs3(v, G, ++tot);
	if (n % 2 == 0) tot++, sbt[tot].push_back(G);
	for (int i = 1; i <= n / 2; i++)
	{
		int i1 = 1, i2;
		for (int j = 1; j <= tot; j++)
			if (sbt[j].size() > sbt[i1].size()) i1 = j;
		i2 = i1 == 1 ? 2 : 1;
		for (int j = 1; j <= tot; j++)
			if (j != i1 && sbt[j].size() > sbt[i2].size()) i2 = j;
		printf("? %d %d\n", sbt[i1][sbt[i1].size() - 1],
			sbt[i2][sbt[i2].size() - 1]);
		sbt[i1].pop_back(); sbt[i2].pop_back();
		fflush(stdout);
		scanf("%d", &x);
		if (dep[x] > dep[ans]) ans = x;
	}
	return printf("! %d\n", ans), 0;
}