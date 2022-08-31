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

const int MAXN = 35005;
const int MAXM = 55;

int n, m, a[MAXN], pre[MAXN], lst[MAXN], f[MAXM][MAXN], mx[MAXN << 2], tag[MAXN << 2];

inline void Pushup(int x)
{
	mx[x] = max(mx[x << 1], mx[x << 1 | 1]);
}

inline void Pushdown(int x)
{
	if (tag[x])
	{
		tag[x << 1] += tag[x];
		mx[x << 1] += tag[x];
		tag[x << 1 | 1] += tag[x];
		mx[x << 1 | 1] += tag[x];
		tag[x] = 0;
	}
}

inline void Modify(int x, int l, int r, int p, int v)
{
	if (l == r)
	{
		tag[x] = 0, mx[x] = v;
		return ;
	}
	Pushdown(x);
	int mid = l + r >> 1;
	if (p <= mid)
		Modify(x << 1, l, mid, p, v);
	else
		Modify(x << 1 | 1, mid + 1, r, p, v);
	Pushup(x);
}

inline void Modify(int x, int l, int r, int ql, int qr, int v)
{
	if (l == ql && r == qr)
	{
		tag[x] += v, mx[x] += v;
		return ;
	}
	Pushdown(x);
	int mid = l + r >> 1;
	if (qr <= mid)
		Modify(x << 1, l, mid, ql, qr, v);
	else if (ql > mid)
		Modify(x << 1 | 1, mid + 1, r, ql, qr, v);
	else
		Modify(x << 1, l, mid, ql, mid, v), Modify(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
	Pushup(x);
}

inline int Query(int x, int l, int r, int ql, int qr)
{
	if (l == ql && r == qr)
		return mx[x];
	Pushdown(x);
	int mid = l + r >> 1;
	if (qr <= mid)
		return Query(x << 1, l, mid, ql, qr);
	if (ql > mid)
		return Query(x << 1 | 1, mid + 1, r, ql, qr);
	return max(Query(x << 1, l, mid, ql, mid), Query(x << 1 | 1, mid + 1, r, mid + 1, qr));
}

inline void Dp(int k)
{
	for (int i = 1; i <= n; i ++)
		Modify(1, 1, n, i, f[k - 1][i - 1]);
	for (int i = 1; i <= n; i ++)
		Modify(1, 1, n, pre[i] + 1, i, 1), f[k][i] = Query(1, 1, n, 1, i);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read(), pre[i] = lst[a[i]], lst[a[i]] = i;
	for (int j = 1; j <= m; j ++)
		Dp(j);
	return printf("%d\n", f[m][n]), 0;
}