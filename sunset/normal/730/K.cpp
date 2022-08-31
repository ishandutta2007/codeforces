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

const int MAXN = 400005;
const int MAXM = 2000005;

int n, m, S, T, e_cnt, ql, qr, hed[MAXN], p[MAXM], v[MAXM], par[MAXN], f[MAXN], dep[MAXN], lnk[MAXN], dir[MAXM];
vector <int> cir[MAXN];
pii q[MAXM];

inline void Addedge(int x, int y)
{
	p[++ e_cnt] = y; v[e_cnt] = hed[x]; hed[x] = e_cnt;
	p[++ e_cnt] = x; v[e_cnt] = hed[y]; hed[y] = e_cnt;
}

inline void Dfs(int x, int e)
{
	for (int i = hed[x], y; i; i = v[i])
		if (i ^ e ^ 1)
			if (!dep[y = p[i]])
				dep[y] = dep[x] + 1, par[y] = x, f[y] = i >> 1, lnk[x] = y, Dfs(y, i);
			else if (dep[y] < dep[x])
				cir[lnk[y]].pb(i >> 1);
}

inline void Sol()
{
	n = Read(), m = Read(), S = Read(), T = Read();
	for (int i = 1; i <= n; i ++)
		dep[i] = hed[i] = par[i] = f[i] = lnk[i] = 0, cir[i].clear();
	for (int i = 1; i <= m; i ++)
		dir[i] = -1;
	e_cnt = dep[S] = 1;
	for (int i = 1; i <= m; i ++)
		Addedge(Read(), Read());
	Dfs(S, 0);
	if (!dep[T])
		return (void)puts("No");
	q[qr = 1] = mp(T, ql = 0);
	while (ql ^ qr)
	{
		int x = q[++ ql].xx, d = q[ql].yy;
		while (par[x] && !~dir[f[x]])
		{
			dir[f[x]] = d;
			for (auto e : cir[x])
			{
				dir[e] = d;
				if (p[e << 1] == par[x])
					q[++ qr] = mp(p[e << 1 | 1], d ^ 1);
				else
					q[++ qr] = mp(p[e << 1], d ^ 1);
			}
			x = par[x];
		}
	}
	for (int i = 1; i <= m; i ++)
		if (!~dir[i])
			return (void)puts("No");
	puts("Yes");
	for (int i = 1; i <= m; i ++)
		if (dir[i] ^ (dep[p[i << 1]] < dep[p[i << 1 | 1]]))
			printf("%d %d\n", p[i << 1], p[i << 1 | 1]);
		else
			printf("%d %d\n", p[i << 1 | 1], p[i << 1]);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
		Sol();
	return 0;
}