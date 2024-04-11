#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

inline int read()
{
	int res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	return bo ? ~res + 1 : res;
}

const int N = 1e6 + 5, ZZQ = 998244353;

int n, fac[N], inv[N], ans;

int main()
{
	n = read();
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % ZZQ;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (ZZQ - ZZQ / i) * inv[ZZQ % i] % ZZQ;
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * inv[i] * inv[i - 1] % ZZQ;
	ans = fac[n];
	for (int i = 1; i < n; i++)
		ans = (1ll * (fac[i] - 1) * fac[n - i] % ZZQ
			* fac[n] % ZZQ * inv[i] % ZZQ * inv[n - i] + ans) % ZZQ;
	std::cout << ans << std::endl;
	return 0;
}