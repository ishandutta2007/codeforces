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

const int mod = 1e9 + 7;

inline int Qow(int x, int y)
{
	int r = 1;
	for (; y; y >>= 1, x = 1LL * x * x % mod)
		if (y & 1)
			r = 1LL * r * x % mod;
	return r;
}

inline int F(int a, int q)
{
	if (q <= 0)
		return 0;
	if (a == 1)
		return q;
	return 1LL * (Qow(a, q) - 1) * Qow(a - 1, mod - 2) % mod;
}

inline int G(int a, int q)
{
	if (q <= 0)
		return 0;
	if (a == 1)
		return (1LL * q * (q + 1) >> 1) % mod;
	int v = Qow(a - 1, mod - 2);
	return 1LL * (1LL * (Qow(a, q) - 1) * a % mod * v % mod + mod - q) * v % mod;
}

inline int Solve(int n, int k, int A_1, int A_0, int B_1, int B_0, int S1_1, int S2_1, int S_0)
{
	if (n == 1)
		return (1LL * S1_1 * B_0 % mod * Qow(mod + 1 - B_1, mod - 2) + S_0) % mod;
	
	int q = (n - 1) / k, r = n - q * k, A__1, A__0, B__1, B__0, S1__1, S2__1, S__0, x, y;
	
	x = 1LL * B_1 * Qow(A_1, q - 1) % mod, y = (1LL * A_0 * B_1 % mod * F(A_1, q - 1) % mod + B_0) % mod;
	A__1 = Qow(x, mod - 2), A__0 = (mod - 1LL * y * A__1 % mod) % mod;
	
	x = 1LL * B_1 * Qow(A_1, q) % mod, y = (1LL * A_0 * B_1 % mod * F(A_1, q) % mod + B_0) % mod;
	B__1 = Qow(x, mod - 2), B__0 = (mod - 1LL * y * B__1 % mod) % mod;

	S1__1 = (1LL * S2_1 * A_1 % mod * F(A_1, q) + S1_1) % mod;
	S2__1 = (1LL * S2_1 * A_1 % mod * F(A_1, q - 1) + S1_1) % mod;

	S__0 = (1LL * S2_1 * A_0 % mod * (1LL * r * F(A_1, q) % mod + 1LL * k * G(A_1, q - 1) % mod) + S_0) % mod;
	
	return Solve(k, r, A__1, A__0, B__1, B__0, S1__1, S2__1, S__0);
}

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	for (int T = Read(); T; T --)
	{
		int n = Read(), k = Read(), d = __gcd(n, k);
		n /= d, k /= d;
		printf("%d\n", 1LL * Solve(n, k, 1, 1, mod + 1 >> 1, 1, 1, 1, 0) * Qow(n, mod - 2) % mod);
	}
}