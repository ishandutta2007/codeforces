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
const LL INF = 1LL << 40;

struct Node { int l, r, L, R; } q[MAXN << 5];
int n, m, ql, qr, qL, qR, a[MAXN], cnt[MAXN];
LL f[25][MAXN], cur;

inline void Solve(LL *f, LL *g, int l, int r, int L, int R)
{
	if (l > r)
		return ;
	int mid = l + r >> 1, nxt = min(mid, R), bes = 0;
	LL val = INF;
	while (qR < mid)
		cur += cnt[a[++ qR]] ++;
	while (qR > mid)
		cur -= -- cnt[a[qR --]];
	while (qL < nxt)
		cur -= -- cnt[a[qL ++]];
	while (qL > nxt)
		cur += cnt[a[-- qL]] ++;
	while (qL >= L)
	{
		LL tmp = g[qL - 1] + cur;
		if (tmp < val)
			val = tmp, bes = qL;
		cur += cnt[a[-- qL]] ++;
	}
	f[mid] = val;
	q[++ qr] = {l, mid - 1, L, bes};
	q[++ qr] = {mid + 1, r, bes, R};
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read();
	for (int i = 1; i <= n; i ++)
		a[i] = Read(), f[0][i] = INF;
	for (int i = 1; i <= m; i ++)
	{
		mset(cnt, 0);
		cur = ql = qr = qR = 0, qL = 1;
		q[++ qr] = {1, n, 1, n};
		while (ql ^ qr)
			ql ++, Solve(f[i], f[i - 1], q[ql].l, q[ql].r, q[ql].L, q[ql].R);
	}
	return printf("%lld\n", f[m][n]), 0;
}