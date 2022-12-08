#include <bits/stdc++.h>

using namespace std;

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

long long inv(long long n) {
	return quickpow(n, mod - 2);
}

long long Inv[1000005];

inline void invWork() {
	Inv[1] = 1;
	for (int i = 2; i < 1000005; ++i) {
		Inv[i] = 1ll * (mod - mod / i) * Inv[mod % i] % mod;
	}
}

long long fac[1000005], ifac[1000005];

void facWork() {
	fac[0] = ifac[0] = 1;
	for (int i = 1; i < 1000005; ++i) {
		fac[i] = fac[i - 1] * i % mod;
		ifac[i] = ifac[i - 1] * Inv[i] % mod;
	}
}

long long C(int n, int m) {
	return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}

const int i2 = inv(2);

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (n == m) {
		cout << 1ll * n * k % mod << '\n';
		return;
	}
	long long ans = 0;
	for (int i = 1; i <= m; ++i) {
		ans += i * C(n - i - 1, m - i) % mod * quickpow(i2, n - i) % mod;
	}
	ans %= mod;
	cout << ans * k % mod << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	invWork();
	facWork();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}