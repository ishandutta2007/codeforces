#include <bits/stdc++.h>

// 20030830

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5, E = 55, M = 5e6 + 5;

int n, m, d, ecnt, nxt[M], adj[M], go[M], ToT, dfn[M], low[M], top, stk[M],
tot, bel[M], vis[M], typ[M], ecnt2, nxt2[M], adj2[M], go2[M], f[M];
char s[N][E];
bool ins[M];

int which(int x, int y)
{
	return (x - 1) * d + y;
}

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
}

void add_edge2(int u, int v)
{
	nxt2[++ecnt2] = adj2[u]; adj2[u] = ecnt2; go2[ecnt2] = v;
}

void dfs(int u)
{
	dfn[u] = low[u] = ++ToT;
	ins[stk[++top] = u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!dfn[v])
		{
			dfs(v);
			low[u] = Min(low[u], low[v]);
		}
		else if (ins[v]) low[u] = Min(low[u], dfn[v]);
	if (dfn[u] == low[u])
	{
		bel[u] = ++tot; ins[u] = 0; int v;
		while (v = stk[top--], v != u) bel[v] = tot, ins[v] = 0;
	}
}

int main()
{
	int x, y;
	n = read(); m = read(); d = read();
	while (m--)
	{
		x = read(); y = read();
		for (int i = 1; i <= d; i++)
			add_edge(which(x, i), which(y, i % d + 1));
	}
	for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n * d; i++) if (!dfn[i]) dfs(i);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
		{
			int u = which(i, j);
			if (s[i][j] == '1' && vis[bel[u]] < i)
				vis[bel[u]] = i, typ[bel[u]]++;
		}
	for (int u = 1; u <= n * d; u++)
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (bel[u] != bel[v]) add_edge2(bel[u], bel[v]);
	for (int u = 1; u <= tot; u++)
	{
		for (int e = adj2[u], v = go2[e]; e; e = nxt2[e], v = go2[e])
			f[u] = Max(f[u], f[v]);
		f[u] += typ[u];
	}
	std::cout << f[bel[which(1, 1)]] << std::endl;
	return 0;
}