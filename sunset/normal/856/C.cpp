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

const int MAXN = 2005;
const int mod = 998244353;

int n, b, c, a[MAXN], p[MAXN], q[MAXN], f[MAXN][11], g[MAXN][11], fac[MAXN];

inline void Solve()
{
	n = Read(), b = c = 0, fac[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		a[i] = Read(), fac[i] = 1LL * fac[i - 1] * i % mod;
		int x = a[i], v = 0;
		while (x)
			x /= 10, v ++;
		if (v & 1)
			p[++ b] = a[i] % 11;
		else
			q[++ c] = a[i] % 11;
	}
	mset(f, 0), mset(g, 0);
	f[0][0] = g[0][0] = 1;
	for (int i = 1; i <= b; i ++)
	{
		mset(g, 0);
		for (int j = 0; j <= b >> 1; j ++)
			for (int k = 0; k < 11; k ++)
				if (f[j][k])
					g[j][(k + p[i]) % 11] = (g[j][(k + p[i]) % 11] + f[j][k]) % mod,
					g[j + 1][(k + 11 - p[i]) % 11] = (g[j + 1][(k + 11 - p[i]) % 11] + f[j][k]) % mod;
		mcpy(f, g);
	}
	mset(f, 0);
	for (int i = 0; i < 11; i ++)
		f[0][i] = 1LL * g[b >> 1][i] * fac[b >> 1] % mod * fac[b + 1 >> 1] % mod;
	for (int i = 1, x = b + 1 >> 1, y = b + 2 >> 1; i <= c; i ++)
	{
		mset(g, 0);
		for (int j = 0; j < i; j ++)
			for (int k = 0; k < 11; k ++)
				g[j + 1][(k + q[i]) % 11] = (g[j + 1][(k + q[i]) % 11] + 1LL * (j + y) * f[j][k]) % mod,
				g[j][(k + 11 - q[i]) % 11] = (g[j][(k + 11 - q[i]) % 11] + 1LL * (i - j - 1 + x) * f[j][k]) % mod;
		mcpy(f, g);
	}
	int ret = 0;
	for (int i = 0; i <= c; i ++)
		ret = (ret + f[i][0]) % mod;
	printf("%d\n", ret);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
		Solve();
	return 0;
}