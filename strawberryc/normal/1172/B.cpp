#include <bits/stdc++.h>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 2e5 + 5, M = N << 1, ZZQ = 998244353;

int n, ecnt, nxt[M], adj[N], go[M], f[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u, int fu)
{
	int cnt = 0, fc = 1, fac = 1;
	f[u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u), cnt++;
	for (int i = 1; i <= cnt; i++)
		fac = 1ll * fac * i % ZZQ;
	f[u] = u == 1 ? fac : 1ll * fac * (cnt + 1) % ZZQ;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
			f[u] = 1ll * f[u] * f[v] % ZZQ;
}

int main()
{
	int x, y;
	n = read();
	for (int i = 1; i < n; i++)
		x = read(), y = read(), add_edge(x, y);
	dfs(1, 0);
	std::cout << 1ll * n * f[1] % ZZQ << std::endl;
	return 0;
}