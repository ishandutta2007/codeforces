#include <string>
#include <iostream>
using namespace std;
const int mod = 1000000009;
int binpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	}
	return ret;
}
int calc(int a, int b, int n) {
	// sum of a^i * b^(n-i) for i=0 to n
	if (n == 0) return 1;
	if (n % 2 == 0) {
		return (1LL * b * calc(a, b, n - 1) + binpow(a, n)) % mod;
	}
	return 1LL * (a + b) * calc(1LL * a * a % mod, 1LL * b * b % mod, n / 2) % mod;
}
int main() {
	int n, a, b, k;
	string s;
	cin >> n >> a >> b >> k >> s;
	swap(a, b);
	int ra = a, rb = b;
	a = binpow(a, k);
	b = binpow(b, k);
	int ret = 0;
	for (int i = 0; i < k; ++i) {
		int r = n / k + 1;
		if (1LL * r * k + i > n) --r;
		int res = calc(a, b, r);
		int ea = i, eb = n % k - i;
		if (eb < 0) eb += k;
		int aug = 1LL * res * binpow(ra, ea) % mod * binpow(rb, eb) % mod;
		if (s[i] == '+') ret = (ret + aug) % mod;
		else ret = (ret + mod - aug) % mod;
	}
	cout << ret << '\n';
	return 0;
}