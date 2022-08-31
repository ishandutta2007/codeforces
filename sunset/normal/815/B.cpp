#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define fill(x, y) memset(x, y, sizeof x)
#define copy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair < int, int > pa;

inline int read()
{
	int sc = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') sc = sc * 10 + ch - '0', ch = getchar();
	return sc * f;
}

const int MAXN = 200005;
const int mod = 1e9 + 7;

int fac[MAXN], inv[MAXN], n, a[MAXN], b[MAXN], ans;

inline int qpow(int x, int y) { int ret = 1; for (; y; y >>= 1, x = 1LL * x * x % mod) if (y & 1) ret = 1LL * ret * x % mod; return ret; }
inline int C(int x, int y) { return 1LL * fac[x] * inv[y] % mod * inv[x - y] % mod; }

inline void inc(int &x, int y) { x += y; if (x >= mod) x -= mod; }
inline void dec(int &x, int y) { x -= y; if (x < 0) x += mod; }

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = read(); fac[0] = 1;
	for (int i = 1; i <= n; i ++) a[i] = read(), fac[i] = 1LL * fac[i - 1] * i % mod;
   inv[n] = qpow(fac[n], mod - 2);
	for (int i = n - 1; ~i; i --) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
	if (n & 1)
	{
		int t = n & 3, d = n >> 2 << 1;
		for (int i = 1; i <= t; i ++)
		{
			int cnt = 0;
			for (int j = i; j + t <= n + i; j += 2) 
				inc(b[i], 1LL * a[j] * C(d, cnt++) % mod);
		}
		if (t == 1) ans = b[1];
		else ans = b[1], inc(ans, b[2]), inc(ans, b[2]), dec(ans, b[3]);
	}
	else
	{
		for (int i = 1; i <= n >> 1; i ++)
		{
			if (n & 2)
				inc(ans, 1LL * (a[i - 1 << 1 | 1] + a[i << 1]) * C(n - 1 >> 1, i - 1) % mod);
			else
				inc(ans, 1LL * (a[i - 1 << 1 | 1] - a[i << 1] + mod) * C(n - 1 >> 1, i - 1) % mod);
		}
	}
	return printf("%d\n", ans), 0;
}