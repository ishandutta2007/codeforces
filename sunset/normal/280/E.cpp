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

const int MAXN = 6005;

pair <double, double> c[MAXN << 1];
double ret, x[MAXN], ans[MAXN];
int n, m, t, p, a, b;

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), t = Read(), a = Read(), b = Read();
	for (int i = 1; i <= n; i ++)
	{
		x[i] = Read();
		if (i == 1)
			c[m ++] = mp(1, 2 * (1 - x[i])), c[m ++] = mp(t, 2 * (t - x[i]));
		else
		{
			for (int j = m - 1; j > p; j --)
				c[j + 2] = c[j];
			m += 2, c[++ p] = mp(ans[i - 1], 0), c[p + 1] = mp(ans[i - 1], 0);
			for (int j = 0; j <= p; j ++)
				c[j].xx += a;
			for (int j = p + 1; j < m; j ++)
				c[j].xx += b;
			for (int j = 0; j < m; j ++)
				c[j].yy += 2 * (c[j].xx - x[i]);
		}
		if (c[0].yy >= 0)
			p = -1, ans[i] = c[0].xx;
		else
		{
			for (p = 0; p < m; p ++)
				if (c[p].yy <= 0 && c[p + 1].yy > 0)
					break;
			ans[i] = c[p].xx - c[p].yy * (c[p + 1].xx - c[p].xx) / (c[p + 1].yy - c[p].yy);
		}
	}
	ans[n] = min(ans[n], (double)t);
	for (int i = n - 1; i; i --)
		ans[i] = max(min(ans[i], ans[i + 1] - a), ans[i + 1] - b);
	for (int i = 1; i <= n; i ++)
		printf("%lf%c", ans[i], i == n ? '\n' : ' '), ret += (ans[i] - x[i]) * (ans[i] - x[i]);
	return printf("%lf\n", ret), 0;
}