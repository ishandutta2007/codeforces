#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

map < LL, LL > f, g, h, a, b, c;
LL n, k;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	cin >> n >> k;
	if (k == 1) return puts("1"), 0;
	if (k == 2) return printf("%lld\n", n), 0;
	n -= 2; k -= 3;
	g[n] = 1;
	while (!g.empty())
	{
		h.clear();
		for (auto x : g) if (x.xx) f[-(x.xx - 1 >> 1)] += x.yy, h[x.xx >> 1] += x.yy, h[x.xx - 1 >> 1] += x.yy;
		g = h;
	}
	for (auto x : f)
	{
		if (k >= x.yy) k -= x.yy;
		else
		{
			LL l = 1, r = n, d = -x.xx;
			while (true)
			{
				if (!k && (r - l >> 1) == d) return printf("%lld\n", l + 1 + d), 0;
				LL m = l + r >> 1;
				a.clear(); b.clear(); c.clear();
				a[r - l >> 1] = b[r - l >> 1] = 1;
				while (!b.empty())
				{
					c.clear();
					for (auto x : b) if (x.xx) a[x.xx - 1 >> 1] += x.yy, c[x.xx >> 1] += x.yy, c[x.xx - 1 >> 1] += x.yy;
					b = c;
				}
				if (k >= a[d]) k -= a[d], l = m + 1;
				else r = m - 1;
			}
		}
	}
}