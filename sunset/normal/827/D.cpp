#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pii;

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
const int INF = 0x3f3f3f3f;

int f[MAXN], u[MAXN], v[MAXN], w[MAXN], p[MAXN], n, m, g[18][MAXN], h[18][MAXN], dep[MAXN], ans[MAXN], e[18][MAXN];
vector < pii > adj[MAXN], a[MAXN];
bool t[MAXN];

inline int Find(int x) { while (x ^ f[x]) x = f[x] = f[f[x]]; return x; }

inline void Dfs(int x)
{
	for (auto e : adj[x])
	{
		int y = e.xx, w = e.yy;
		if (y == g[0][x])
			continue;
		g[0][y] = x; h[0][y] = w;
		for (int i = 1; i <= 17; i ++)
			g[i][y] = g[i - 1][g[i - 1][y]], h[i][y] = max(h[i - 1][y], h[i - 1][g[i - 1][y]]);
		dep[y] = dep[x] + 1;
		Dfs(y);
	}
}

inline void Build()
{
	sort(p + 1, p + m + 1, [&](int x, int y) { return w[x] < w[y]; });

	for (int i = 1; i <= n; i ++)
		f[i] = i;

	for (int i = 1; i <= m; i ++)
	{
		int x = u[p[i]], y = v[p[i]], z = w[p[i]];
		if (Find(x) ^ Find(y))
			f[Find(x)] = Find(y), t[p[i]] = 1, adj[x].pb(mp(y, z)), adj[y].pb(mp(x, z));
	}

	Dfs(1);
}

inline int Query(int x, int y)
{
	int ret = 0;
	if (dep[x] < dep[y])
		swap(x, y);
	if (dep[x] ^ dep[y])
		for (int i = 17; ~i; i --)
			if (dep[x] - dep[y] >> i & 1)
				ret = max(ret, h[i][x]), x = g[i][x];
	if (x == y)
		return ret;
	for (int i = 17; ~i; i --)
		if (g[i][x] ^ g[i][y])
			ret = max(ret, max(h[i][x], h[i][y])), x = g[i][x], y = g[i][y];

	return max(ret, max(h[0][x], h[0][y]));
}

inline void Add(int x, int y, int w)
{
	if (dep[x] < dep[y])
		swap(x, y);
	if (dep[x] ^ dep[y])
		for (int i = 17; ~i; i --)
			if (dep[x] - dep[y] >> i & 1)
				e[i][x] = min(e[i][x], w), x = g[i][x];
	if (x ^ y)
	{
		for (int i = 17; ~i; i --)
			if (g[i][x] ^ g[i][y])
				e[i][x] = min(e[i][x], w), e[i][y] = min(e[i][y], w), x = g[i][x], y = g[i][y];
		e[0][x] = min(e[0][x], w);
		e[0][y] = min(e[0][y], w);
	}
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= m; i ++)
		u[i] = Read(), v[i] = Read(), w[i] = Read(), p[i] = i;

	Build();

	mset(e, INF);

	for (int i = 1; i <= m; i ++)
		if (!t[i])
			ans[i] = Query(u[i], v[i]) - 1, Add(u[i], v[i], w[i]);
		else if (dep[u[i]] < dep[v[i]])
			f[v[i]] = i;
		else
			f[u[i]] = i;

	for (int j = 17; j; j --)
		for (int i = 1; i <= n; i ++)
			e[j - 1][i] = min(e[j - 1][i], e[j][i]), e[j - 1][g[j - 1][i]] = min(e[j - 1][g[j - 1][i]], e[j][i]);

	for (int i = 2; i <= n; i ++)
		ans[f[i]] = e[0][i] == INF ? -1 : e[0][i] - 1;

	for (int i = 1; i <= m; i ++)
		printf("%d%c", ans[i], i == m ? '\n' : ' ');

	return 0;
}