#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

const int MAXN = 200005;

int n, m, tim, f[18][MAXN], p[MAXN], q[MAXN], g[MAXN], s[MAXN], dep[MAXN], dfn[MAXN], siz[MAXN];
vector <pair <pii, int>> c[MAXN];
vector <int> adj[MAXN];

inline int Anc(int x, int k)
{
	for (int i = 17; ~i; i --)
		if (k >> i & 1)
			x = f[i][x];
	return x;
}

inline int LCA(int x, int y)
{
	if (dep[x] < dep[y])
		y = Anc(y, dep[y] - dep[x]);
	else if (dep[x] > dep[y])
		x = Anc(x, dep[x] - dep[y]);
	if (x == y)
		return x;
	for (int i = 17; ~i; i --)
		if (f[i][x] ^ f[i][y])
			x = f[i][x], y = f[i][y];
	return f[0][x];
}

inline void Dfs(int x)
{
	siz[x] = 1, dfn[x] = ++ tim;
	for (auto y : adj[x])
		Dfs(y), siz[x] += siz[y];
}

inline void Modify(int *b, int x, int v)
{
	for (; x <= n; x += x & -x)
		b[x] += v;
}

inline int Query(int *b, int x)
{
	int r = 0;
	for (; x; x -= x & -x)
		r += b[x];
	return r;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 2; i <= n; i ++)
		f[0][i] = Read(), dep[i] = dep[f[0][i]] + 1, adj[f[0][i]].pb(i);
	Dfs(1);
	for (int j = 1; j <= 17; j ++)
		for (int i = 1; i <= n; i ++)
			f[j][i] = f[j - 1][f[j - 1][i]];
	for (int i = 1, x, y, w; i <= m; i ++)
		x = Read(), y = Read(), w = Read(), c[LCA(x, y)].pb(mp(mp(x, y), w));
	for (int x = n; x; x --)
	{
		for (auto y : adj[x])
			s[x] += g[y];
		Modify(p, dfn[x], s[x]);
		Modify(p, dfn[x] + siz[x], -s[x]);
		g[x] = s[x];
		for (auto cir : c[x])
		{
			int u = cir.xx.xx, v = cir.xx.yy, w = cir.yy;
			g[x] = max(g[x], Query(p, dfn[u]) + Query(p, dfn[v]) - s[x] - Query(q, dfn[u]) - Query(q, dfn[v]) + w);
		}
		Modify(q, dfn[x], g[x]);
		Modify(q, dfn[x] + siz[x], -g[x]);
	}
	return printf("%d\n", g[1]), 0;
}