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

const int MAXN = 1100005;

int fac[MAXN], inv[MAXN], n, m, a, q, mod, pw[MAXN], f[MAXN];

inline int C(int x, int y)
{
	if (x < y)
		return 0;
	return 1LL * fac[x] * inv[y] % mod * inv[x - y] % mod;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), a = Read(), q = Read();
	pw[0] = fac[0] = inv[0] = fac[1] = inv[1] = 1;
	do
	{
		mod ++;
		pw[mod] = 1LL * pw[mod - 1] * a % q;
	} while (pw[mod] ^ 1);
	for (int i = 2; i <= m; i ++)
		fac[i] = 1LL * fac[i - 1] * i % mod, inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 2; i <= m; i ++)
		inv[i] = 1LL * inv[i] * inv[i - 1] % mod;
	for (int i = n; i; i --)
		f[i] = (f[i + 1] + C(m, n - i)) % mod;
	for (int i = 1; i <= n; i ++)
		printf("%d%c", pw[f[i]], i == n ? '\n' : ' ');
	return 0;
}