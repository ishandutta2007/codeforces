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

const int MAXN = 55;
const int INF = 0x3f3f3f3f;

int n, m, s, siz[MAXN], val[MAXN][MAXN], g[MAXN][MAXN], f[MAXN][MAXN][MAXN][MAXN];
vector <int> adj[MAXN], trans[MAXN][MAXN];

inline void Dfs(int x, int p)
{
	for (auto y : adj[x])
		if (y ^ p)
			Dfs(y, x), siz[x] += siz[y];
}

inline int Dp(int p, int x, int cnt, int tot)
{
	if (!tot)
		return 0;
	if (!cnt)
		return INF;
	if (f[p][x][cnt][tot] ^ INF)
		return f[p][x][cnt][tot];
	if (trans[p][x].empty())
		return f[p][x][cnt][tot] = val[p][x] + Dp(x, p, tot - cnt, tot - cnt);
	for (auto y : trans[p][x])
		for (int i = 0; i <= cnt; i ++)
			Dp(x, y, i, tot);
	for (int i = 0; i <= trans[p][x].size(); i ++)
		for (int j = 0; j <= cnt; j ++)
			g[i][j] = 0;
	g[0][0] = INF;
	for (int i = 0; i < trans[p][x].size(); i ++)
		for (int j = 0; j <= cnt; j ++)
			for (int k = 0; j + k <= cnt; k ++)
				g[i + 1][j + k] = max(g[i + 1][j + k], min(g[i][j], Dp(x, trans[p][x][i], k, tot)));
	return f[p][x][cnt][tot] = g[trans[p][x].size()][cnt] + val[p][x];
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	mset(f, INF);
	n = Read();
	for (int i = 1, x, y, w; i < n; i ++)
		x = Read(), y = Read(), w = Read(), adj[x].pb(y), adj[y].pb(x), val[x][y] = val[y][x] = w;
	for (int x = 1; x <= n; x ++)
		for (auto p : adj[x])
			for (auto y : adj[x])
				if (y ^ p)
					trans[p][x].pb(y);
	s = Read(), m = Read();
	for (int i = 1; i <= m; i ++)
		siz[Read()] ++;
	Dfs(s, 0);
	int ret = INF;
	for (auto y : adj[s])
		ret = min(ret, Dp(s, y, siz[y], m));
	return printf("%d\n", ret), 0;
}