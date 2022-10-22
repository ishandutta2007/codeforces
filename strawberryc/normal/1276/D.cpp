#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 2e5 + 5, M = N << 1, rqy = 998244353;

int n, ecnt, nxt[M], adj[N], go[M], id[M], f[N], g[N], h[N], tot, p[N], lf[N], rg[N];

void add_edge(int u, int v, int i)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; id[ecnt] = i;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; id[ecnt] = i;
}

void dfs(int u, int fu, int to)
{
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) dfs(v, u, id[e]);
	tot = 0;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu) p[++tot] = v;
	lf[0] = rg[tot + 1] = 1;
	for (int i = 1; i <= tot; i++) lf[i] = 1ll * lf[i - 1] * f[p[i]] % rqy;
	for (int i = tot; i >= 1; i--) rg[i] = 1ll * rg[i + 1] * g[p[i]] % rqy;
	f[u] = h[u] = rg[1];
	int tmp = 1, cc = 0;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			cc++;
			int delta = 1ll * lf[cc - 1] % rqy * rg[cc + 1] % rqy * h[v] % rqy;
			f[u] = (f[u] + delta) % rqy;
			if (id[e] < to) tmp = 1ll * tmp * g[v] % rqy, g[u] = (g[u] + delta) % rqy;
			else tmp = 1ll * tmp * f[v] % rqy, h[u] = (h[u] + delta) % rqy;
		}
	g[u] = (g[u] + tmp) % rqy;
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y, i);
	dfs(1, 0, 0);
	return std::cout << f[1] << std::endl, 0;
}