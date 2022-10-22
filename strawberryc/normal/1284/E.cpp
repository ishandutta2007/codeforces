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

const int N = 2505;

int n, m, ax[N], ay[N];
ll ans;

struct point
{
	int x, y; double theta;
} a[N];

inline bool comp(point a, point b)
{
	bool ia = a.y < 0 || (a.y == 0 && a.x < 0),
		ib = b.y < 0 || (b.y == 0 && b.x < 0);
	if (ia != ib) return ia > ib;
	return 1ll * a.x * b.y - 1ll * a.y * b.x > 0;
}

int nxt(int i) {return i % m + 1;}

void jiejuediao(int O)
{
	m = 0;
	for (int i = 1; i <= n; i++)
		if (i != O) a[++m] = (point) {ax[i] - ax[O], ay[i] - ay[O]},
			a[m].theta = atan2(a[m].y, a[m].x);
	std::sort(a + 1, a + m + 1, comp);
	ans += 1ll * m * (m - 1) * (m - 2) * (m - 3) / 24;
	for (int i = 1, p = 1, cnt = 0; i <= m; i++, cnt--)
	{
		if (i == p) p = nxt(p), cnt++;
		while (1ll * a[i].x * a[p].y - 1ll * a[i].y * a[p].x > 0)
			p = nxt(p), cnt++;
		ans -= 1ll * (cnt - 1) * (cnt - 2) * (cnt - 3) / 6;
	}
}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(ax[i]), read(ay[i]);
	for (int i = 1; i <= n; i++) jiejuediao(i);
	return std::cout << ans << std::endl, 0;
}