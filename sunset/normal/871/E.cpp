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

const int MAXN = 30005;
const int MAXM = 205;

int n, m, idx[MAXN], par[MAXN], p[MAXM][MAXN], d[MAXM][MAXN];
vector <int> adj[MAXN];
vector <pii> sub[MAXN];
bool v[MAXN];

inline void GG()
{
	puts("-1");
	exit(0);
}

inline void Dfs(int x, int *d, int dep, int p)
{
	if (dep ^ d[x])
		GG();
	for (auto y : adj[x])
		if (y ^ p)
			Dfs(y, d, dep + 1, x);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= m; i ++)
	{
		for (int j = 1; j <= n; j ++)
			if (!(d[i][j] = Read()))
			{
				if (idx[i])
					GG();
				idx[i] = j;
			}
		if (!idx[i])
			GG();
	}
	p[1][0] = idx[1], v[idx[1]] = true;
	for (int i = 2; i <= m; i ++)
	{
		for (int j = 1; j <= n; j ++)
			if (d[1][j] + d[i][j] == d[1][idx[i]])
			{
				if (p[i][d[1][j]])
					GG();
				p[i][d[1][j]] = j, v[j] = true;
			}
		for (int j = 1; j <= d[1][idx[i]]; j ++)
		{
			if (!p[i][j])
				GG();
			if (par[p[i][j]] && par[p[i][j]] != p[i][j - 1])
				GG();
			par[p[i][j]] = p[i][j - 1];
		}
	}
	for (int i = 1; i <= n; i ++)
		if (!v[i])
		{
			int x = -1, pos = 0;
			for (int j = 1; j <= m; j ++)
			{
				int dis = d[1][i] + d[1][idx[j]] - d[j][i] >> 1;
				if (x < dis)
					x = dis, pos = p[j][dis];
			}
			sub[pos].pb(mp(d[1][i], i));
		}
	for (int i = 1; i <= n; i ++)
	{
		sort(sub[i].begin(), sub[i].end());
		for (int j = 0, dep = d[1][i], lst = i; j < sub[i].size(); j ++)
		{
			if (j && (sub[i][j].xx ^ sub[i][j - 1].xx))
				lst = sub[i][j - 1].yy, dep = d[1][lst];
			if (sub[i][j].xx - dep - 1)
				GG();
			par[sub[i][j].yy] = lst;
		}
	}
	for (int i = 1; i <= n; i ++)
		if (par[i])
			adj[par[i]].pb(i), adj[i].pb(par[i]);
		else if (i ^ idx[1])
			GG();
	for (int i = 1; i <= m; i ++)
		Dfs(idx[i], d[i], 0, 0);
	for (int x = 1; x <= n; x ++)
		if (par[x])
			printf("%d %d\n", x, par[x]);
	return 0;
}