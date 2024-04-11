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

const int N = 2e5 + 5, M = N << 1;

int n, m, k, ecnt, nxt[M], adj[N], go[M], len, que[N], d1[N], dn[N], a[N],
lm[N], rm[N], ans;
bool vis[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void bfs(int S, int *dis)
{
	memset(vis, 0, sizeof(vis));
	dis[que[len = 1] = S] = 0; vis[S] = 1;
	for (int i = 1; i <= len; i++)
	{
		int u = que[i];
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		{
			if (vis[v]) continue;
			dis[que[++len] = v] = dis[u] + 1;
			vis[v] = 1;
		}
	}
}

inline bool comp(int x, int y) {return d1[x] > d1[y];}

int main()
{
	int x, y;
	read(n); read(m); read(k);
	for (int i = 1; i <= k; i++) read(a[i]);
	while (m--) read(x), read(y), add_edge(x, y);
	bfs(1, d1); bfs(n, dn);
	std::sort(a + 1, a + k + 1, comp);
	for (int i = 1, mx = 0; i <= k; i++)
	{
		if (i > 1) ans = std::max(ans, d1[a[i]] + 1 + mx);
		mx = std::max(mx, dn[a[i]]);
	}
	return std::cout << std::min(d1[n], ans) << std::endl, 0;
}