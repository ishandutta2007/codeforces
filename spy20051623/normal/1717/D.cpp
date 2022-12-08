#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;

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

long long inv[100005];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < 100005; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[100005], ifac[100005];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 100005; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

i64 C(int n, int m) {
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

void solve() {
	int n, k;
	std::cin >> n >> k;
	if (k >= n) std::cout << quickpow(2, n) << '\n';
	else {
		i64 ans = 0;
		for (int i = 0; i <= k; ++i) {
			ans = (ans + C(n, i)) % mod;
		}
		std::cout << ans << '\n';
	}
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