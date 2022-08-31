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

const int MAXN = 200005;

int n, top, a[MAXN], L[MAXN], R[MAXN], sta[MAXN], pre[MAXN][31], nxt[MAXN][31];
LL ans;

inline void Solve(int x, int l, int r)
{
	for (int i = 0; i < 30; i ++)
		if (!(a[x] >> i & 1))
			l = max(l, pre[x][i] + 1), r = min(r, nxt[x][i] - 1);
	ans -= 1LL * (r - x + 1) * (x - l + 1);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), ans = 1LL * n * (n + 1) >> 1;
	for (int i = 1; i <= n; i ++)
		a[i] = Read();
	for (int i = 1; i <= n; sta[++ top] = i ++)
		while (top && a[i] > a[sta[top]])
			R[sta[top --]] = i - 1;
	while (top)
		R[sta[top --]] = n;
	for (int i = n; i; sta[++ top] = i --)
		while (top && a[i] >= a[sta[top]])
			L[sta[top --]] = i + 1;
	while (top)
		L[sta[top --]] = 1;
	for (int i = 1; i <= n; i ++)
		for (int j = 0; j < 30; j ++)
			if (a[i - 1] >> j & 1)
				pre[i][j] = i - 1;
			else
				pre[i][j] = pre[i - 1][j];
	for (int j = 0; j < 30; j ++)
		nxt[n + 1][j] = n + 1;
	for (int i = n; i; i --)
		for (int j = 0; j < 30; j ++)
			if (a[i + 1] >> j & 1)
				nxt[i][j] = i + 1;
			else
				nxt[i][j] = nxt[i + 1][j];
	for (int i = 1; i <= n; i ++)
		Solve(i, L[i], R[i]);
	return printf("%lld\n", ans), 0;
}