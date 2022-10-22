#include <map>
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

template <class T>
inline T Max(const T &a, const T &b) {return a > b ? a : b;}

const int N = 1e5 + 5, M = N << 1;

typedef long long ll;

int n, ZZQ, ecnt, nxt[M], adj[N], go[M], val[M], p10[N], p10inv[N],
sze[N], maxs[N], tot, D[N], Down[N];
bool vis[N];
ll ans;

std::map<int, int> arr;

void exgcd(int a, int b, int &x, int &y)
{
	if (!b) return (void) (x = 1, y = 0);
	exgcd(b, a % b, y, x); y -= a / b * x;
}

int getinv(int u, int ZZQ)
{
	int x, y;
	exgcd(u, ZZQ, x, y);
	return (x % ZZQ + ZZQ) % ZZQ;
}

void add_edge(int u, int v, int w)
{
	nxt[++ecnt] = adj[u]; adj[u] = ecnt; go[ecnt] = v; val[ecnt] = w;
	nxt[++ecnt] = adj[v]; adj[v] = ecnt; go[ecnt] = u; val[ecnt] = w;
}

void dfs1(int u, int fu)
{
	sze[u] = 1; maxs[u] = 0;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!vis[v = go[e]] && v != fu)
			dfs1(v, u), sze[u] += sze[v],
			maxs[u] = Max(maxs[u], sze[v]);
}

void dfs2(int u, int fu, int rt, int &G)
{
	if (Max(maxs[u], sze[rt] - sze[u]) < Max(maxs[G], sze[rt] - sze[G]))
		G = u;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!vis[v = go[e]] && v != fu) dfs2(v, u, rt, G);
}

int calcG(int u)
{
	dfs1(u, 0);
	int G = u;
	dfs2(u, 0, u, G);
	return G;
}

void zzq_ak_wc_2019(int u, int fu, int dep, int down, int up)
{
	D[++tot] = dep; Down[tot] = down; arr[up]++;
	for (int e = adj[u], v; e; e = nxt[e])
		if (!vis[v = go[e]] && v != fu)
			zzq_ak_wc_2019(v, u, dep + 1, (10ll * down + val[e]) % ZZQ,
			(1ll * val[e] * p10[dep] + up) % ZZQ);
}

void zzq_ak_ctsc_2019(int u, int op, int bas_dep, int bas_num)
{
	tot = 0;
	zzq_ak_wc_2019(u, 0, bas_dep, bas_num, bas_num);
	ll sp = ans;
	for (int i = 1; i <= tot; i++)
		ans += op * arr[1ll * p10inv[D[i]] * (ZZQ - Down[i]) % ZZQ];
	arr.clear();
}

void zzq_ak_ioi_2019(int u)
{
	int G = calcG(u); vis[G] = 1;
	ll st = ans;
	zzq_ak_ctsc_2019(G, 1, 0, 0);
	for (int e = adj[G], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) zzq_ak_ctsc_2019(v, -1, 1, val[e] % ZZQ);
	for (int e = adj[G], v = go[e]; e; e = nxt[e], v = go[e])
		if (!vis[v]) zzq_ak_ioi_2019(v);
}

int main()
{
	int x, y, z;
	n = read(); ZZQ = read();
	p10[0] = p10inv[0] = 1;
	p10inv[1] = getinv(10, ZZQ);
	for (int i = 1; i <= n; i++)
		p10[i] = 10ll * p10[i - 1] % ZZQ;
	for (int i = 2; i <= n; i++)
		p10inv[i] = 1ll * p10inv[i - 1] * p10inv[1] % ZZQ;
	for (int i = 1; i < n; i++)
		x = read() + 1, y = read() + 1, z = read(), add_edge(x, y, z);
	zzq_ak_ioi_2019(1);
	std::cout << ans - n << std::endl;
	return 0;
}