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
const int mod = 1e9 + 7;

int n, m, ans, tot, a[MAXN], f[MAXN];

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
	n = Read();
	for (int i = 1; i <= n; i ++)
		tot += a[i] = Read(), m = max(m, a[i]);
	f[0] = 0, f[1] = 1LL * (tot - 1) * (tot - 1) % mod * Qow(tot, mod - 2) % mod;
	for (int i = 2; i <= m; i ++)
		f[i] = (2LL * f[i - 1] - f[i - 2] - 1LL * (tot - 1) * Qow(tot - i + 1, mod - 2)) % mod;
	for (int i = 1; i <= n; i ++)
		ans = (ans + f[a[i]]) % mod;
	return printf("%d\n", (ans + mod) % mod), 0;
}