#include <cstdio>
#include <algorithm>
using namespace std;
const long long mod = 998244353;
long long mp(long long b, long long e) {
	if (e == 0) return 1;
	long long a = mp(b, e / 2);
	a = a * a % mod;
	if (e & 1) a = a * b % mod;
	return a;
}
int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	long long fac[n], inv[n], ans = 0;
	fac[0] = inv[0] = 1;
	for (int i = 1; i < n; ++i) fac[i] = i * fac[i - 1] % mod;
	for (int i = 1; i < n; ++i) inv[i] = mp(fac[i], mod - 2);
	for (int i = 1; i <= n; ++i) {
		if (n / i >= k) ans = (ans + fac[n / i - 1] * inv[k - 1] % mod * inv[n / i - k] % mod) % mod;
	}
	printf("%lld", ans);
	return 0;
}