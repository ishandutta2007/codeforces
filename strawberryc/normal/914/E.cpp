#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

typedef long long ll;

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 2e5 + 5, M = N << 1, C = (1 << 20) + 5;

int n, ecnt, nxt[M], adj[N], go[M], a[N], sze[N], maxs[N], cnt[C];
bool vis[N];
char s[N];
ll ans[N], pyz[N];

void add_edge(int u, int v)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u;
}

void dfs1(int u, int fu)
{
	sze[u] = 1; maxs[u] = 0;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu && !vis[v])
			dfs1(v, u), sze[u] += sze[v],
			maxs[u] = Max(maxs[u], sze[v]);
}

void dfs2(int u, int fu, int rt, int &G)
{
	if (Max(maxs[u], sze[rt] - sze[u]) < Max(maxs[G], sze[rt] - sze[G]))
		G = u;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu && !vis[v])
			dfs2(v, u, rt, G);
}

int calcG(int u)
{
	dfs1(u, 0);
	int G = u;
	dfs2(u, 0, u, G);
	return G;
}

void zzq_ak_wc_2019(int u, int fu)
{
	a[u] = a[fu] ^ (1 << s[u] - 'a');
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu && !vis[v])
			zzq_ak_wc_2019(v, u);
}

void zzq_ak_apio_2019(int u, int fu)
{
	cnt[a[u]]++;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu && !vis[v])
			zzq_ak_apio_2019(v, u);
}

void zzq_ak_ctsc_2019(int u, int fu)
{
	cnt[a[u]] = 0;
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu && !vis[v])
			zzq_ak_ctsc_2019(v, u);
}

void zzq_ak_noi_2019(int u, int fu, int rt, int op)
{
	sze[u] = 1;
	pyz[u] = cnt[(1 << s[rt] - 'a') ^ a[u]];
	for (int i = 0; i < 20; i++)
		pyz[u] += cnt[(1 << i) ^ (1 << s[rt] - 'a') ^ a[u]];
	for (int e = adj[u], v; e; e = nxt[e])
		if ((v = go[e]) != fu && !vis[v])
			zzq_ak_noi_2019(v, u, rt, op),
			sze[u] += sze[v], pyz[u] += pyz[v];
	if (u == rt) ans[u] += (pyz[u] + sze[u] >> 1) * op;
	else ans[u] += pyz[u] * op;
}

void zzq_ak_ioi_2019(int u)
{
	u = calcG(u); vis[u] = 1;
	zzq_ak_wc_2019(u, 0); zzq_ak_apio_2019(u, 0);
	zzq_ak_noi_2019(u, 0, u, 1); zzq_ak_ctsc_2019(u, 0);
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) zzq_ak_wc_2019(v, u), zzq_ak_apio_2019(v, u),
			zzq_ak_noi_2019(v, u, u, -1),
			ans[u] -= pyz[v] + sze[v] >> 1, zzq_ak_ctsc_2019(v, 0);
	for (int e = adj[u], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) zzq_ak_ioi_2019(v);
}

int main()
{
	int x, y;
	n = read();
	for (int i = 1; i < n; i++)
		x = read(), y = read(), add_edge(x, y);
	scanf("%s", s + 1);
	zzq_ak_ioi_2019(1);
	for (int i = 1; i <= n; i++)
		printf("%I64d ", ans[i]);
	std::cout << std::endl;
	return 0;
}