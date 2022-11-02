#include <iostream>
using namespace std;
const int mod = 1000003;
int modpow(int a, int b, int m) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % m;
		a = 1LL * a * a % m;
		b >>= 1;
	}
	return ret;
}
long long bitsum(long long x) {
	// popcount(1) + popcount(2) + ... + popcount(x)
	long long ret = 0;
	while (x) {
		x >>= 1;
		ret += x;
	}
	return ret;
}
long long n, m;
int main() {
	cin >> n >> m;
	if (n <= 62 && (1LL << n) < m) cout << 1 << ' ' << 1 << endl;
	else {
		int ret1 = 1, b = modpow(2, n % (mod - 1), mod);
		if (m >= mod) ret1 = 0;
		else for (int i = 0; i < m; i++) ret1 = 1LL * ret1 * (b - i + mod) % mod;
		int r = (n % (mod - 1)) * (m % (mod - 1)) % (mod - 1);
		int aug = (n + bitsum(m - 1)) % (mod - 1);
		int ret3 = modpow(2, (r - aug + mod - 1) % (mod - 1), mod);
		ret1 = 1LL * ret1 * modpow(modpow(2, aug, mod), mod - 2, mod) % mod;
		cout << (ret3 - ret1 + mod) % mod << ' ' << ret3 << endl;
	}
	return 0;
}