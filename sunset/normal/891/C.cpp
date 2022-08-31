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

const int MAXN = 500005;

int n, m, q, val, top, f[MAXN], u[MAXN], v[MAXN], w[MAXN], siz[MAXN], sta[MAXN];
vector <pii> edg[MAXN], qry[MAXN];
bool ans[MAXN];

inline int Find(int x)
{
	while (x ^ f[x])
		x = f[x];
	return x;
}

inline bool Merge(int x, int y)
{
	x = Find(x), y = Find(y);
	if (x == y)
		return false;
	if (siz[x] > siz[y])
		swap(x, y);
	f[x] = y, siz[y] += siz[x];
	sta[++ top] = x;
	return true;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= m; i ++)
		u[i] = Read(), v[i] = Read(), w[i] = Read(), edg[w[i]].pb(mp(u[i], v[i])), val = max(val, w[i]);
	q = Read();
	for (int i = 1; i <= q; ans[i ++] = true)
		for (int c = Read(), x; c; c --)
			x = Read(), qry[w[x]].pb(mp(i, x));
	for (int i = 1; i <= n; i ++)
		f[i] = i, siz[i] = 1;
	for (int i = 1; i <= val; i ++)
	{
		for (int l = 0, r = 0; l < qry[i].size(); l = r)
		{
			while (r < qry[i].size() && qry[i][r].xx == qry[i][l].xx)
				r ++;
			for (int j = l; j < r; j ++)
				if (!Merge(u[qry[i][j].yy], v[qry[i][j].yy]))
					ans[qry[i][j].xx] = false, j = r;
			while (top)
			{
				int x = sta[top --];
				siz[f[x]] -= siz[x], f[x] = x;
			}
		}
		for (auto e : edg[i])
			Merge(e.xx, e.yy);
		top = 0;
	}
	for (int i = 1; i <= q; i ++)
		puts(ans[i] ? "YES" : "NO");
	return 0;
}