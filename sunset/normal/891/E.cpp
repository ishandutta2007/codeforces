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

const int MAXN = 5005;
const int mod = 1e9 + 7;

int n, m, a[MAXN], f[MAXN];

inline int Qow(int x, int y)
{
	int r = 1;
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1)
			r = 1LL * r * x % mod;
	return r;
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read(), m = Read(), f[0] = 1;
	for (int i = 1; i <= n; i ++)
	{
		a[i] = Read();
		for (int j = i; j; j --)
			f[j] = (1LL * f[j] * a[i] - f[j - 1] + mod) % mod;
		f[0] = 1LL * f[0] * a[i] % mod;
	}
	int cur = 1, bas = Qow(n, mod - 2), ret = 0;
	for (int i = 0; i <= n; i ++)
		ret = (1LL * cur * f[i] + ret) % mod, cur = 1LL * cur * bas % mod * (m - i) % mod;
	return printf("%d\n", (f[0] - ret + mod) % mod), 0;
}