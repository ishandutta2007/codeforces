#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)
#define Rof(i, a, b) for (i = a; i >= b; i--)

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

template <class T>
inline T Min(const T &a, const T &b) {return a < b ? a : b;}

const int N = 2e5 + 5;
const ll INF = 1e18;

int n;
ll f[N], g[N], pmin[N], smin[N], ans = INF;

struct point
{
	int x, y, lev;
} a[N];

ll dist(point a, point b)
{
	return abs(a.x - b.x) + abs(a.y - b.y);
}

inline bool comp(point a, point b)
{
	return a.lev < b.lev || (a.lev == b.lev &&
		a.x + a.lev - a.y < b.x + b.lev - b.y);
}

int main()
{
	int i, lst = 1, now = 2;
	n = read() + 1;
	For (i, 1, n - 1) a[i].x = read(), a[i].y = read(),
		a[i].lev = Max(a[i].x, a[i].y);
	std::sort(a + 1, a + n + 1, comp);
	while (now <= n)
	{
		int nxt = now, frm = now, p = lst;
		while (a[nxt].lev == a[now].lev) nxt++;
		while (a[frm].lev == a[now].lev && a[frm].x <= a[frm].y) frm++;
		pmin[lst - 1] = smin[now] = INF;
		For (i, lst, now - 1) pmin[i] =
			Min(pmin[i - 1], g[i] - a[i].x - a[i].y);
		Rof (i, now - 1, lst) smin[i] =
			Min(smin[i + 1], g[i] + a[i].x - a[i].y);
		For (i, now, frm - 1)
		{
			while (p < now && a[p].x <= a[i].x) p++;
			f[i] = Min(pmin[p - 1] + a[i].x + a[i].y,
				smin[p] - a[i].x + a[i].y);
		}
		For (i, lst, now - 1) pmin[i] =
			Min(pmin[i - 1], g[i] - a[i].x + a[i].y);
		Rof (i, now - 1, lst) smin[i] =
			Min(smin[i + 1], g[i] - a[i].x - a[i].y);
		p = lst;
		For (i, frm, nxt - 1)
		{
			while (p < now && a[p].y >= a[i].y) p++;
			f[i] = Min(pmin[p - 1] + a[i].x - a[i].y,
				smin[p] + a[i].x + a[i].y);
		}
		g[now] = g[nxt - 1] = INF;
		For (i, now, nxt - 1)
		{
			g[now] = Min(g[now], f[i] + dist(a[i], a[nxt - 1])
				+ dist(a[nxt - 1], a[now]));
			g[nxt - 1] = Min(g[nxt - 1], f[i] + dist(a[i], a[now])
				+ dist(a[now], a[nxt - 1]));
		}
		For (i, now + 1, nxt - 2)
			g[i] = Min(g[now] + dist(a[now], a[i]),
				g[nxt - 1] + dist(a[nxt - 1], a[i]));
		lst = now; now = nxt;
	}
	For (i, lst, now - 1) ans = Min(ans, g[i]);
	std::cout << ans << std::endl;
	return 0;
}