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

const int MAXN = 305;
const int mod = 1e9 + 7;

int n, ans, a[MAXN], f[MAXN], g[MAXN], fac[MAXN], inv[MAXN], C[MAXN][MAXN];

inline void Solve(int l)
{
	mset(g, 0);
	for (int i = 1; i <= l; i ++)
		for (int j = 0; i + j <= n; j ++)
			g[i + j] = (1LL * f[j] * C[l - 1][i - 1] % mod * fac[l] % mod * inv[i] + g[i + j]) % mod;
	mcpy(f, g);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1; i <= n; i ++)
	{
		a[i] = Read();
		for (int j = 2; j * j <= a[i]; j ++)
			if (a[i] % j == 0)
				while (a[i] % (j * j) == 0)
					a[i] /= j * j;
	}
	for (int i = 0; i <= n; i ++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= i; j ++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
	}
	sort(a + 1, a + n + 1);
	f[0] = fac[0] = fac[1] = inv[0] = inv[1] = 1;
	for (int i = 2; i <= n; i ++)
		fac[i] = 1LL * fac[i - 1] * i % mod, inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= n; i ++)
		inv[i] = 1LL * inv[i] * inv[i - 1] % mod;
	for (int l = 1, r = 1; l <= n; Solve(r - l), l = r)
		while (a[r] == a[l])
			r ++;
	for (int i = n, t = 1; i; i --, t = -t)
		ans = (1LL * fac[i] * f[i] * t % mod + ans) % mod;
	return printf("%d\n", (ans + mod) % mod), 0;
}