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

const int N = 1e5 + 5, M = N << 1;

int n, ecnt, nxt[M], adj[N], go[M], d[N], ans2, Root;
bool is0, is1;

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
	d[u]++; d[v]++;
}

void dfs(int u, int fu, int dep)
{
	if (d[u] == 1)
	{
		if (dep & 1) is0 = 1; else is1 = 1;
	}
	int cnt = 0;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu)
		{
			dfs(v, u, dep + 1);
			if (d[v] == 1) cnt++;
		}
	if (cnt > 1) ans2 -= cnt - 1;
}

int main()
{
	int x, y;
	read(n);
	for (int i = 1; i < n; i++) read(x), read(y), add_edge(x, y);
	for (int i = 1; i <= n; i++) if (d[i] > 1) Root = i;
	ans2 = n - 1; dfs(Root, 0, 0);
	return std::cout << (is0 && is1 ? 3 : 1) << " " << ans2 << std::endl, 0;
}