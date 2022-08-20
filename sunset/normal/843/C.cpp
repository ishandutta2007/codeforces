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

int par[MAXN], siz[MAXN], st[MAXN], dep[MAXN], tp, n;
vector <int> adj[MAXN], c[MAXN], r;
vector <pair <int, pii>> ans;

inline void Dfs(int x, int p)
{
	bool f = 1;
	siz[x] = 1;
	for (auto y : adj[x])
		if (y ^ p)
		{
			Dfs(y, x), siz[x] += siz[y];
			if (siz[y] > n >> 1)
				f = 0;
		}
	if (n - siz[x] > n >> 1)
		f = 0;
	if (f)
		r.pb(x);
}

inline void Dfs2(int x, int p)
{
	par[st[tp ++] = x] = p;
	if (dep[x] >= 3)
		c[st[1]].pb(x);
	for (auto y : adj[x])
		if (y ^ p)
			dep[y] = dep[x] + 1, Dfs2(y, x);
	tp --;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1, x, y; i < n; i ++)
		x = Read(), y = Read(), adj[x].pb(y), adj[y].pb(x);
	Dfs(1, 0);
	if (r.size() == 1)
		Dfs2(r[0], 0);
	else
		Dfs2(r[0], r[1]), Dfs2(r[1], r[0]);
	for (int i = 1; i <= n; i ++)
		if (c[i].size())
		{
			int cur = i;
			for (auto x : c[i])
				ans.pb(mp(par[i], mp(cur, x))), ans.pb(mp(x, mp(par[x], i))), cur = x;
			ans.pb(mp(par[i], mp(cur, i)));
		}
	printf("%d\n", ans.size());
	for (auto x : ans)
		printf("%d %d %d\n", x.xx, x.yy.xx, x.yy.yy);
}