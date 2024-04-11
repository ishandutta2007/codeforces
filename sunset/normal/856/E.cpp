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

struct Node
{
	int opt, x, y;
} e[MAXN];

int n, m, r, tot, x[MAXN], y[MAXN], p[MAXN], q[MAXN], mx[MAXN << 2], rnk[MAXN], pos[MAXN], rot[MAXN];
pii a[MAXN], b[MAXN];

inline bool Cmp(pii u, pii v) { return 1LL * u.xx * v.yy - 1LL * u.yy * v.xx > 0; }

inline void Modify(int x, int l, int r, int p, int v)
{
	if (l == r)
		return (void)(mx[x] = v);
	int mid = l + r >> 1;
	if (p <= mid)
		Modify(x << 1, l, mid, p, v);
	else
		Modify(x << 1 | 1, mid + 1, r, p, v);
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}

inline int Query(int x, int l, int r, int ql, int qr)
{
	if (l == ql && r == qr)
		return mx[x];
	int mid = l + r >> 1;
	if (qr <= mid)
		return Query(x << 1, l, mid, ql, qr);
	if (ql > mid)
		return Query(x << 1 | 1, mid + 1, r, ql, qr);
	return max(Query(x << 1, l, mid, ql, mid), Query(x << 1 | 1, mid + 1, r, mid + 1, qr));
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	r = Read(), m = Read();
	for (int i = 1; i <= m; i ++)
	{
		e[i].opt = Read();
		if (e[i].opt == 1)
			n ++, x[n] = e[i].x = Read(), y[n] = e[i].y = Read();
		else if (e[i].opt == 2)
			e[i].x = Read();
		else
			e[i].x = Read(), e[i].y = Read();
	}
	for (int i = 1; i <= n; i ++)
		a[i] = mp(x[i] + r, y[i]);
	sort(a + 1, a + n + 1, Cmp);
	for (int i = 1; i <= n; i ++)
		p[i] = lower_bound(a + 1, a + n + 1, mp(x[i] + r, y[i]), Cmp) - a;
	for (int i = 1; i <= n; i ++)
		b[i] = mp(r - x[i], y[i]);
	sort(b + 1, b + n + 1, Cmp);
	for (int i = 1; i <= n; i ++)
		q[i] = lower_bound(b + 1, b + n + 1, mp(r - x[i], y[i]), Cmp) - b;
	for (int i = 1; i <= n; i ++)
		pos[i] = i;
	sort(pos + 1, pos + n + 1, [&](int x, int y) { return mp(p[x], q[x]) < mp(p[y], q[y]); });
	for (int i = 1; i <= n; i ++)
		rnk[pos[i]] = i;
	for (int i = 1, cur = 0; i <= m; i ++)
		if (e[i].opt == 1)
			cur ++, Modify(1, 1, n, rnk[cur], q[cur]);
		else if (e[i].opt == 2)
			Modify(1, 1, n, rnk[e[i].x], 0);
		else
		{
			int idx = e[i].x, idy = e[i].y;
			Modify(1, 1, n, rnk[idx], 0);
			Modify(1, 1, n, rnk[idy], 0);
			pii x, y;
			if (p[idx] < p[idy])
				x = a[p[idx]];
			else
				x = a[p[idy]];
			if (q[idx] < q[idy])
				y = b[q[idx]];
			else
				y = b[q[idy]];
			if (1LL * x.xx * y.xx - 1LL * x.yy * y.yy > 0)
				puts("NO");
			else
			{
				p[n + 1] = lower_bound(a + 1, a + n + 1, x, Cmp) - a;
				q[n + 1] = lower_bound(b + 1, b + n + 1, y, Cmp) - b;
				int t = lower_bound(pos + 1, pos + n + 1, n + 1, [&](int x, int y) { return mp(p[x], q[x]) < mp(p[y], q[y]); }) - pos;
				if (Query(1, 1, n, t, n) >= q[n + 1])
					puts("NO");
				else
					puts("YES");
			}
			Modify(1, 1, n, rnk[idx], q[idx]);
			Modify(1, 1, n, rnk[idy], q[idy]);
		}
}