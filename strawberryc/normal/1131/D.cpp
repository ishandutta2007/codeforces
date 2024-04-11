#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 1005, M = N * 2, L = 1e6 + 5;

int n, m, fa[M], ecnt, nxt[L], adj[M], go[L], d[M], H, T, Q[M], f[M];
char s[N][N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	d[v]++;
}

int cx(int x)
{
	if (fa[x] != x) fa[x] = cx(fa[x]);
	return fa[x];
}

void zm(int x, int y)
{
	int ix = cx(x), iy = cx(y);
	if (ix != iy) fa[iy] = ix;
}

int main()
{
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for (int i = 1; i <= n + m; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '=') zm(i, j + n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s[i][j] == '<') add_edge(cx(i), cx(j + n));
			else if (s[i][j] == '>') add_edge(cx(j + n), cx(i));
	int cnt = 0;
	for (int i = 1; i <= n + m; i++)
	{
		if (fa[i] == i && !d[i]) Q[++T] = i, f[i] = 1;
		if (fa[i] == i) cnt++;
	}
	while (H < T)
	{
		int u = Q[++H];
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		{
			if (!(--d[v])) Q[++T] = v;
			f[v] = std::max(f[v], f[u] + 1);
		}
	}
	if (T < cnt) return puts("No"), 0;
	puts("Yes");
	for (int i = 1; i <= n; i++) printf("%d ", f[cx(i)]);
	std::cout << std::endl;
	for (int i = 1; i <= m; i++) printf("%d ", f[cx(i + n)]);
	std::cout << std::endl;
	return 0;
}