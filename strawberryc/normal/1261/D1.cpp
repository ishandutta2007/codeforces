#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

const int N = 2e5 + 5, rqy = 998244353;

int n, k, h[N], pw[N], p2[N], fac[N], inv[N], dif, ans;

int C(int n, int m)
{
	return 1ll * fac[n] * inv[m] % rqy * inv[n - m] % rqy;
}

int main()
{
	int pw2 = 1;
	read(n); read(k);
	pw[0] = p2[0] = fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		read(h[i]);
		pw[i] = 1ll * pw[i - 1] * k % rqy;
		p2[i] = 1ll * p2[i - 1] * (k - 2) % rqy;
		fac[i] = 1ll * fac[i - 1] * i % rqy;
	}
	for (int i = 2; i <= n; i++)
		inv[i] = 1ll * (rqy - rqy / i) * inv[rqy % i] % rqy;
	for (int i = 2; i <= n; i++) inv[i] = 1ll * inv[i] * inv[i - 1] % rqy;
	for (int i = 1; i <= n; i++)
		if (h[i] != h[i % n + 1]) dif++;
	for (int i = 1; i <= dif; i++)
	{
		pw2 = (pw2 + pw2) % rqy;
		int delta = pw2;
		if (!(i & 1)) delta = (delta - C(i, i >> 1) + rqy) % rqy;
		delta = 499122177ll * delta % rqy;
		ans = (1ll * delta * C(dif, i) % rqy * p2[dif - i] % rqy
			* pw[n - dif] + ans) % rqy;
	}
	return std::cout << ans << std::endl, 0;
}