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

int n, m, a[MAXN], sum[MAXN << 2], val[MAXN << 2];
vector <int> add[MAXN], del[MAXN];
bool rev[MAXN << 2];
LL ans;

inline void Rev(int x)
{
	rev[x] ^= 1, sum[x] = val[x] - sum[x];
}

inline void Pushdown(int x)
{
	if (rev[x])
		Rev(x << 1), Rev(x << 1 | 1), rev[x] = 0;
}

inline void Pushup(int x)
{
	sum[x] = sum[x << 1] + sum[x << 1 | 1];
}

inline void Build(int x, int l, int r)
{
	val[x] = r - l + 1;
	if (l == r)
		return ;
	int mid = l + r >> 1;
	Build(x << 1, l, mid), Build(x << 1 | 1, mid + 1, r);
}

inline void Modify(int x, int l, int r, int ql, int qr)
{
	if (l == ql && r == qr)
		return Rev(x);
	int mid = l + r >> 1;
	Pushdown(x);
	if (qr <= mid)
		Modify(x << 1, l, mid, ql, qr);
	else if (ql > mid)
		Modify(x << 1 | 1, mid + 1, r, ql, qr);
	else
		Modify(x << 1, l, mid, ql, mid), Modify(x << 1 | 1, mid + 1, r, mid + 1, qr);
	Pushup(x);
}

inline int Query(int x, int l, int r, int ql, int qr)
{
	if (l == ql && r == qr)
		return sum[x];
	int mid = l + r >> 1;
	Pushdown(x);
	if (qr <= mid)
		return Query(x << 1, l, mid, ql, qr);
	if (ql > mid)
		return Query(x << 1 | 1, mid + 1, r, ql, qr);
	return Query(x << 1, l, mid, ql, mid) + Query(x << 1 | 1, mid + 1, r, mid + 1, qr);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), ans = 1LL * n * (n - 1) * (n - 2) / 6;
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= m; i ++)
	{
		int l = lower_bound(a + 1, a + n + 1, Read()) - a, r = upper_bound(a + 1, a + n + 1, Read()) - a - 1;
		if (l <= r && l >= 1 && l <= n && r >= 1 && r <= n)
			add[l].pb(r), del[r].pb(l);
	}
	Build(1, 1, n);
	for (int i = 1; i <= n; i ++)
	{
		for (auto x : add[i])
			Modify(1, 1, n, i, x);
		int ret = 0;
		if (i > 1)
			ret += i - 1 - Query(1, 1, n, 1, i - 1);
		if (i < n)
			ret += Query(1, 1, n, i + 1, n);
		ans -= 1LL * ret * (ret - 1) / 2;
		for (auto x : del[i])
			Modify(1, 1, n, x, i);
	}
	cout << ans << endl;
	return 0;
}