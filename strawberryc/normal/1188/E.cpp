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

const int N = 2e6 + 5, djq = 998244353;

int k, n, a[N], cnt[N], fac[N], inv[N], ans;

int C(int n, int m) {return 1ll * fac[n] * inv[m] % djq * inv[n - m] % djq;}

int main()
{
	fac[0] = inv[0] = inv[1] = 1;
	for (int i = 1; i < N; i++) fac[i] = 1ll * fac[i - 1] * i % djq;
	for (int i = 2; i < N; i++) inv[i] = 1ll * (djq - djq / i) * inv[djq % i] % djq;
	for (int i = 2; i < N; i++) inv[i] = 1ll * inv[i] * inv[i - 1] % djq;
	read(k); int cur = 0;
	for (int i = 1; i <= k; i++) read(a[i]), n += a[i];
	std::sort(a + 1, a + k + 1);
	for (int i = 0, j = 1; i <= a[k]; i++)
	{
		while (a[j] < i) cnt[a[j++] % k]++;
		cur += cnt[(i - 1 + k) % k];
		if (cur > i) return std::cout << ans << std::endl, 0;
		ans = (ans + C(i - cur + k - 1, k - 1)) % djq;
		if (i - cur + j - 2 >= k - 1)
			ans = (ans - C(i - cur + j - 2, k - 1) + djq) % djq;
	}
	return std::cout << ans << std::endl, 0;
}