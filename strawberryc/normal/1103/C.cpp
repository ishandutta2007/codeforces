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

template <class T>
inline void Swap(T &a, T &b) {T t = a; a = b; b = t;}

const int N = 25e4 + 5, M = 1e6 + 5, INF = 0x3f3f3f3f;

int n, m, k, ecnt, nxt[M], adj[N], go[M], dep[N], f[N], g[N], pf[N], pg[N],
dis, st, ed, fa[N], d[N], Root, tot, p[N], w[N][3], t1, a1[N], t2, a2[N];
bool vis[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs(int u)
{
	vis[pf[u] = pg[u] = u] = 1;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!vis[v = go[e]])
		{
			dep[v] = dep[fa[v] = u] + 1; d[u]++;
			dfs(v);
			if (f[v] + 1 > f[u]) g[u] = f[u], pg[u] = pf[u],
				f[u] = f[v] + 1, pf[u] = pf[v];
			else if (f[v] + 1 > g[u]) g[u] = f[v] + 1, pg[u] = pf[v];
		}
		else if (dep[v] < dep[u] && w[u][0] < 2 && v != fa[u])
			w[u][++w[u][0]] = v;
	if (f[u] + g[u] > dis) dis = f[u] + g[u], st = pf[u], ed = pg[u];
}

void output(int u, int v)
{
	t1 = t2 = 0;
	if (dep[u] < dep[v]) Swap(u, v);
	while (dep[u] > dep[v])
		a1[++t1] = u, u = fa[u];
	while (u != v)
		a1[++t1] = u, a2[++t2] = v, u = fa[u], v = fa[v];
	for (int i = 1; i <= t1; i++) printf("%d ", a1[i]);
	printf("%d ", u);
	for (int i = t2; i >= 1; i--) printf("%d ", a2[i]);
	puts("");
}

int main()
{
	int x, y;
	n = read(); m = read(); k = read();
	while (m--)
		x = read(), y = read(), add_edge(x, y);
	dfs(dep[1] = 1);
	for (int i = 1; i <= n; i++) if (!d[i]) p[++tot] = i;
	if (dis + 1 >= (n + k - 1) / k) printf("PATH\n%d\n", dis + 1), output(st, ed);
	else
	{
		puts("CYCLES");
		for (int i = 1; i <= k; i++)
		{
			int u = p[i];
			if (dep[w[u][1]] < dep[w[u][2]]) Swap(w[u][1], w[u][2]);
			if ((dep[u] - dep[w[u][1]]) % 3 != 2)
				printf("%d\n", dep[u] - dep[w[u][1]] + 1),
				output(u, w[u][1]);
			else if ((dep[u] - dep[w[u][2]]) % 3 != 2)
				printf("%d\n", dep[u] - dep[w[u][2]] + 1),
				output(u, w[u][2]);
			else printf("%d\n%d ", dep[w[u][1]] - dep[w[u][2]] + 2, u),
				output(w[u][1], w[u][2]);
		}
	}
	return 0;
}