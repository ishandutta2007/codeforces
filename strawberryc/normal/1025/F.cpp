#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 2005;

int n, cnt[N][N], pt[N];
ll ans;

struct point
{
	int x, y;
	
	friend inline point operator - (point a, point b)
	{
		return (point) {b.x - a.x, b.y - a.y};
	}
	
	friend inline ll operator * (point a, point b)
	{
		return 1ll * a.x * b.y - 1ll * a.y * b.x;
	}
} a[N], OC;

inline bool comp(int i, int j)
{
	point u = OC - a[i], v = OC - a[j];
	bool ia = u.y < 0 || (u.y == 0 && u.x < 0),
		ib = v.y < 0 || (v.y == 0 && v.x < 0);
	return ia != ib ? ia > ib : u * v > 0;
}

int nxt(int i) {return i == n - 1 ? 1 : i + 1;}

void calc(int O)
{
	for (int i = 1; i <= n; i++) if (i != O) pt[i - (i > O)] = i;
	OC = a[O]; std::sort(pt + 1, pt + n, comp);
	for (int i = 1, p = 1, c = -1; i < n; i++, c--)
	{
		if (p == i) p = nxt(p), c++;
		while (p != i && (OC - a[pt[i]]) * (OC - a[pt[p]]) > 0)
			c++, p = nxt(p);
		cnt[O][pt[i]] = c * (c - 1) >> 1;
	}
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(a[i].x), read(a[i].y);
	for (int i = 1; i <= n; i++) calc(i);
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ans += 1ll * cnt[i][j] * cnt[j][i];
	return std::cout << ans << std::endl, 0;
}