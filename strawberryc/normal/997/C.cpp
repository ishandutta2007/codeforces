#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define For(i, a, b) for (i = a; i <= b; i++)

const int N = 1e6 + 5, ZZQ = 998244353;

int n, p3[N], p33[N], fac[N], inv[N], ans;

int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % ZZQ * inv[n - m] % ZZQ;
}

int qpow(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % ZZQ;
		a = 1ll * a * a % ZZQ;
		b >>= 1;
	}
	return res;
}

int main()
{
	int i;
	std::cin >> n;
	p3[0] = p33[0] = 1;
	For (i, 1, n) p3[i] = 3ll * p3[i - 1] % ZZQ;
	For (i, 1, n) p33[i] = 1ll * p3[n] * p33[i - 1] % ZZQ;
	fac[0] = inv[0] = inv[1] = 1;
	For (i, 1, n) fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	For (i, 2, n) inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	For (i, 2, n) inv[i] = 1ll * inv[i] * inv[i - 1] % ZZQ;
	For (i, 0, n)
	{
		int diff, sm;
		if (!i) diff = 0, sm = 1;
		else diff = (p3[i] - 3 + ZZQ) % ZZQ, sm = 3;
		int delta = 1ll * diff * p33[n - i] % ZZQ;
		if (i) delta = (1ll * sm * qpow(p3[n - i] - 1, n) + delta) % ZZQ;
		else delta = (1ll * sm * qpow((p3[n - i] - 3 + ZZQ) %
			ZZQ, n) + delta) % ZZQ;
		if (i & 1) ans = (ans - 1ll * delta * C(n, i) % ZZQ + ZZQ) % ZZQ;
		else ans = (1ll * delta * C(n, i) + ans) % ZZQ;
	}
	std::cout << (p33[n] - ans + ZZQ) % ZZQ << std::endl;
	return 0;
}