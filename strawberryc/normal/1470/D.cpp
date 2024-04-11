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

const int N = 3e5 + 5, M = N << 1;

int n, m, ecnt, nxt[M], adj[N], go[M], tot, seq[N], dfn[N], ansl, ans[N];
bool vis[N], sel[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u)
{
	vis[u] = 1; seq[dfn[u] = ++tot] = u;
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) dfs(v);
}

void work()
{
	int x, y; bool flag = 1;
	read(n); read(m);
	while (m--) read(x), read(y), add_edge(x, y);
	if (dfs(1), tot < n) puts("NO"), flag = 0;
	else for (int i = 1; i <= n; i++)
	{
		int u = seq[i]; sel[u] = 1;
		for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
			if (dfn[v] < dfn[u] && sel[v]) sel[u] = 0;
		if (sel[u]) ans[++ansl] = u;
	}
	if (flag)
	{
		puts("YES"); printf("%d\n", ansl);
		for (int i = 1; i <= ansl; i++) printf("%d ", ans[i]);
		puts("");
	}
	ecnt = tot = ansl = 0;
	for (int i = 1; i <= n; i++) adj[i] = 0, vis[i] = sel[i] = 0;
}

int main()
{
	int T; read(T);
	while (T--) work();
	return 0;
}