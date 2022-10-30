#include <iostream>
using namespace std;
const int mod = 998244353;
int fact[1000009], inv[1000009], factinv[1000009];
int comb(int n, int k) {
	return 1LL * fact[n] * factinv[k] % mod * factinv[n - k] % mod;
}
int binpow(int a, long long b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int main() {
	int n;
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = 1LL * i * fact[i - 1] % mod;
	inv[1] = 1;
	for (int i = 2; i <= n; ++i) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	factinv[0] = 1;
	for (int i = 1; i <= n; ++i) factinv[i] = 1LL * inv[i] * factinv[i - 1] % mod;
	int ret = 0;
	for (int i = 1; i <= n; ++i) {
		int val = 2LL * binpow(3, 1LL * n * (n - i) + i) * comb(n, i) % mod;
		if (i % 2 == 1) ret = (ret + val) % mod;
		else ret = (ret + mod - val) % mod;
	}
	for (int i = 1; i <= n; ++i) {
		int x = mod - binpow(3, n - i);
		int sum = (mod + binpow(x + 1, n) - binpow(x, n)) % mod;
		int aug = 3LL * sum * comb(n, i) % mod;
		if ((n + i) % 2 == 1) ret = (ret + aug) % mod;
		else ret = (ret + mod - aug) % mod;
	}
	cout << ret << '\n';
	return 0;
}