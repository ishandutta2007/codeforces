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

const int N = 2e5 + 5, ZZQ = 998244353;

int n, ecnt, nxt[N], adj[N], go[N], f[N], g[N], h[N][3];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void dfs(int u)
{
	bool lea = 1;
	f[u] = h[u][0] = 1;
	g[u] = h[u][1] = h[u][2] = 0;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
	{
		lea = 0;
		dfs(v);
		g[u] = (1ll * g[u] * f[v] + 1ll * g[v] * f[u]) % ZZQ;
		f[u] = 1ll * f[u] * f[v] % ZZQ;
		h[u][2] = (1ll * g[v] * (h[u][2] + h[u][1]) + 1ll * f[v] * h[u][2]) % ZZQ;
		h[u][1] = (1ll * g[v] * h[u][0] + 1ll * f[v] * h[u][1]) % ZZQ;
		h[u][0] = 1ll * h[u][0] * f[v] % ZZQ;
	}
	f[u] = (f[u] + h[u][2]) % ZZQ;
	g[u] = (g[u] + h[u][2]) % ZZQ;
	if (lea) g[u] = 1;
}

int main()
{
	n = read();
	for (int i = 2; i <= n; i++) add_edge(read(), i);
	return std::cout << (dfs(1), f[1]) << std::endl, 0;
}