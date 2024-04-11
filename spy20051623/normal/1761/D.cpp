#include <bits/stdc++.h>

using i64 = long long;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;

long long inv[N];

inline void invWork() {
	inv[1] = 1;
	for (int i = 2; i < N; ++i) {
		inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
	}
}

long long fac[N], ifac[N];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * inv[i] % mod;
	}
}

i64 C(int n, int m) {
	if (n < m) return 0;
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

i64 pw[N];

void solve() {
	int n, k;
	std::cin >> n >> k;
	if (!k) return std::cout << pw[n] << '\n', void();
	i64 ans = 0;
	for (int i = 1; i + i - 1 <= n && i <= k; ++i) {
		(ans += pw[n - i - i + 1] * C(k - 1, i - 1) % mod * C(n - k, i - 1)) %= mod;
	}
	for (int i = 1; i + i <= n && i <= k; ++i) {
		(ans += pw[n - i - i] * C(k - 1, i - 1) % mod * C(n - k, i)) %= mod;
	}
	ans = (ans % mod + mod) % mod;
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
	pw[0] = 1;
	for (int i = 1; i < N; ++i) {
		pw[i] = pw[i - 1] * 3 % mod;
	}
	int t = 1;
//	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}