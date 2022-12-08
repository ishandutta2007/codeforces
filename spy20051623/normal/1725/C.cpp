#include <bits/stdc++.h>

using i64 = long long;

const int mod = 998244353;

long long quickpow(long long a, long long b) {
	long long res = 1;
	a %= mod;
	while (b) {
		if (b & 1)
			res = res * a % mod;
		b >>= 1;
		a = a * a % mod;
	}
	return res;
}

long long inv[300005];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < 300005; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[300005], ifac[300005];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 300005; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

i64 C(i64 n, i64 m) {
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void solve() {
	i64 n, m;
	std::cin >> n >> m;
	std::vector<i64> a(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> a[i];
		a[i] += a[i - 1];
	}
	if (a[n] % 2 == 1) {
		i64 ans = quickpow(m, n);
		std::cout << ans << '\n';
		return;
	}
	i64 d = a[n] / 2, k = 0;
	std::set<i64> s;
	for (int i = 0; i < n; ++i) {
		s.insert(a[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (s.count(a[i] + d)) ++k;
	}
	if (m == 1 && k) {
		std::cout << "0\n";
		return;
	}
	i64 ans = 0;
	for (int i = 0; i <= k; ++i) {
		ans = (ans + C(k, i) * C(m, i) % mod * fac[i] % mod * quickpow((m + mod - i) % mod, n - k - i) % mod *
					 quickpow((m + mod - 1 - i) % mod, k - i)) % mod;
	}
	std::cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#else
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
#endif
	invWork();
	facWork();
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}