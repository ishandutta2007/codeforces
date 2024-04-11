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

const int N = 3e5 + 5, M = 1e6 + 5, INF = 0x3f3f3f3f;

int n, m, ecnt, nxt[M], adj[N], go[M], id[M], f[N][2], sonx[N], tot,
nm, edg[N], lea[N];
bool siv[N], vis[N];

void add_edge(int u, int v, int i)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; id[ecnt] = i;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; id[ecnt] = i;
}

void dfs(int u)
{
	bool isl = 1;
	vis[u] = 1; f[u][0] = 0; f[u][1] = -INF;
	int son = 0, it = INF;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
	{
		if (vis[v]) continue;
		dfs(v); isl = 0;
		f[u][0] += std::max(f[v][0], f[v][1]);
		int delta = std::max(f[v][0], f[v][1]) - f[v][0] - 1;
		if (delta < it) it = delta, son = e;
	}
	sonx[u] = son;
	if (isl) lea[++tot] = u;
	else f[u][1] = f[u][0] - it;
}

void sfd(int u, int op)
{
	siv[u] = 1;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
	{
		if (siv[v]) continue;
		if (!op || sonx[u] != e) sfd(v, f[v][0] > f[v][1] ? 0 : 1);
		else edg[++nm] = id[e], sfd(v, 0);
	}
}

void work()
{
	int x, y;
	read(n); read(m);
	ecnt = tot = nm = 0;
	for (int i = 1; i <= 3 * n; i++) adj[i] = 0, vis[i] = siv[i] = 0;
	for (int i = 1; i <= m; i++)
		read(x), read(y), add_edge(x, y, i);
	for (int i = 1; i <= 3 * n; i++) if (!vis[i]) dfs(i),
		sfd(i, f[i][0] > f[i][1] ? 0 : 1);
	if (nm >= n)
	{
		puts("Matching");
		for (int i = 1; i <= n; i++) printf("%d ", edg[i]);
		return (void) puts("");
	}
	puts("IndSet");
	for (int i = 1; i <= n; i++) printf("%d ", lea[i]);
	puts("");
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}