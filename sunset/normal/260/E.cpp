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

const int MAXN = 100005;
const int MAXM = 3000005;

struct Node
{
	int l, r, v;
} e[MAXM];

int n, m, tot, a[10], b[10], l[MAXN], rot[MAXN];
pii p[MAXN], q[MAXN];

inline void Modify(int &x, int y, int l, int r, int p)
{
	e[x = ++ tot] = e[y], e[x].v ++;
	if (l == r)
		return ;
	int mid = l + r >> 1;
	if (p <= mid)
		Modify(e[x].l, e[y].l, l, mid, p);
	else
		Modify(e[x].r, e[y].r, mid + 1, r, p);
}

inline int Query(int x, int y, int l, int r, int ql, int qr)
{
	if (l == ql && r == qr)
		return e[x].v - e[y].v;
	int mid = l + r >> 1;
	if (qr <= mid)
		return Query(e[x].l, e[y].l, l, mid, ql, qr);
	if (ql > mid)
		return Query(e[x].r, e[y].r, mid + 1, r, ql, qr);
	return Query(e[x].l, e[y].l, l, mid, ql, mid) + Query(e[x].r, e[y].r, mid + 1, r, mid + 1, qr);
}

inline void Solve()
{
	int l = b[1] + b[4] + b[7], r = l + b[2] + b[5] + b[8];
	if (p[l].xx == p[l + 1].xx || p[r].xx == p[r + 1].xx)
		return ;
	int L = b[7] + b[8] + b[9], R = L + b[4] + b[5] + b[6];
	if (q[L].xx == q[L + 1].xx || q[R].xx == q[R + 1].xx)
		return ;
	L = q[L].xx, R = q[R].xx;
	if (b[1] ^ Query(rot[l], rot[0], 1, m, R + 1, m))
		return ;
	if (b[2] ^ Query(rot[r], rot[l], 1, m, R + 1, m))
		return ;
	if (b[3] ^ Query(rot[n], rot[r], 1, m, R + 1, m))
		return ;
	if (b[4] ^ Query(rot[l], rot[0], 1, m, L + 1, R))
		return ;
	if (b[5] ^ Query(rot[r], rot[l], 1, m, L + 1, R))
		return ;
	if (b[6] ^ Query(rot[n], rot[r], 1, m, L + 1, R))
		return ;
	if (b[7] ^ Query(rot[l], rot[0], 1, m, 0 + 1, L))
		return ;
	if (b[8] ^ Query(rot[r], rot[l], 1, m, 0 + 1, L))
		return ;
	if (b[9] ^ Query(rot[n], rot[r], 1, m, 0 + 1, L))
		return ;
	printf("%lf %lf\n", p[l].xx + 0.5, p[r].xx + 0.5);
	printf("%lf %lf\n", ::l[L] + 0.5, ::l[R] + 0.5);
	exit(0);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
		p[i].xx = q[i].yy = Read(), p[i].yy = q[i].xx = l[i] = Read();
	sort(p + 1, p + n + 1), sort(q + 1, q + n + 1);
	sort(l + 1, l + n + 1), m = unique(l + 1, l + n + 1) - l - 1;
	for (int i = 1; i <= n; i ++)
		p[i].yy = lower_bound(l + 1, l + m + 1, p[i].yy) - l, q[i].xx = lower_bound(l + 1, l + m + 1, q[i].xx) - l;
	for (int i = 1; i <= n; i ++)
		Modify(rot[i], rot[i - 1], 1, m, p[i].yy);
	int c[10];
	for (int i = 1; i <= 9; i ++)
		a[i] = Read(), c[i] = i;
	do
	{
		for (int i = 1; i <= 9; i ++)
			b[i] = a[c[i]];
		Solve();
	} while (next_permutation(c + 1, c + 10));
	return puts("-1"), 0;
}