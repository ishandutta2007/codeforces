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

const int MAXN = 1000005;
const int mod = 1e9 + 7;

int n, m, f[MAXN], g[MAXN], fac[MAXN], inv[MAXN];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), fac[0] = fac[1] = inv[0] = inv[1] = 1;
	if (m >= n)
		return puts("0"), 0;
	for (int i = 2; i <= n; i ++)
		fac[i] = 1LL * fac[i - 1] * i % mod, inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= n; i ++)
		inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
	for (int i = m + 1; i <= n; i ++)
		f[i] = 1LL * fac[i - 2] * (i - m - 1 + g[i - 1] - g[i - m - 1] + mod) % mod, g[i] = (1LL * f[i] * inv[i - 1] + g[i - 1]) % mod;
	return printf("%d\n", 1LL * g[n] * fac[n - 1] % mod), 0;
}