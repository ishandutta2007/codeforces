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

const int MAXN = 1048580;
const int mod = 1e9 + 7;

int n, m, ans, a[MAXN], b[MAXN];
char s[MAXN];

inline void FWT(int *x)
{
	for (int i = 1; i < m; i <<= 1)
		for (int j = 0; j < m; j += i << 1)
			for (int k = 0, u, v; k < i; k ++)
				u = x[j + k], v = x[j + k + i], x[j + k] = (u + v) % mod, x[j + k + i] = (u - v) % mod;
}

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
	n = Read(), m = 1 << n;
	scanf("%s", s);
	for (int i = 0; i < m; i ++)
		a[i] = s[i] - '0', b[i] = a[i] ^ 1;
	FWT(a); FWT(b);
	for (int i = 0; i < m; i ++)
		a[i] = 1LL * a[i] * b[i] % mod;
	FWT(a);
	for (int i = 0, v = Qow(m, mod - 2); i < m; i ++)
		a[i] = 1LL * a[i] * v % mod;
	for (int i = 0; i < m; i ++)
		ans = (ans + (1LL << __builtin_popcount(i)) * a[i]) % mod;
	return printf("%d\n", (3LL * ans) % mod), 0;
}