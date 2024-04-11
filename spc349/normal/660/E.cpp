#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long power(int a, int b) {
	if (!b) return 1;
	long long tmp = power(a, b >> 1);
	return b & 1 ? tmp * tmp % mod * a % mod : tmp * tmp % mod;
}

long long pw[1000010], fac[1000010], inv[1000010], ipw[1000010];

long long C(int n, int k) {
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

int main () {
	fac[0] = 1;
	for (int i = 1; i <= 1000005; i++) {
		fac[i] = fac[i - 1] * i % mod;
	}
	inv[1000005] = power(fac[1000005], mod - 2);
	for (int i = 1000004; i >= 0; i--) {
		inv[i] = inv[i + 1] * (i + 1) % mod;
	}
	int n, m; cin >> n >> m;
	if (m == 1) {
		cout << n + 1 << endl;
		return 0;
	}
	long long invm = power(m - 1, mod - 2);
	long long M = m * power(m - 1, mod - 2) % mod;
	pw[0] = ipw[0] = 1;
	for (int i = 1; i <= 1000005; i++) {
		pw[i] = pw[i - 1] * M % mod;
		ipw[i] = ipw[i - 1] * invm % mod;
	}
	long long cur = 0;
	for (int i = 0; i <= n - 1; i++) {
		cur = (cur + 1ll * C(n - i - 1, 0) * pw[i]) % mod;
	}
	long long B = power(m - 1, n), ans = m * ipw[1] % mod * cur % mod;
	long long MUL = power((M - 1 + mod) % mod, mod - 2);
	long long tmp = m;
	for (int x = 2; x <= n; x++) {
		// (M - 1) * new =  - C(n - 1, x - 1) + cur - C(n - 1, x - 2)
		cur = (cur - C(n - 1, x - 1) - C(n - 1, x - 2) + mod + mod) % mod;
		cur = cur * MUL % mod;
		tmp = tmp * m % mod;
		ans = (ans + tmp * ipw[x] % mod * cur) % mod;
	}
	ans = ans * B % mod;
	ans = (ans + power(m, n)) % mod;
	cout << ans << endl;
	return 0;
}