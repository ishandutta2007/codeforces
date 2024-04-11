#include <cstdio>
#include <algorithm>
#include <vector>
#include <bitset>
using namespace std;
const long long mod = 998244353;
/*bitset<32001> bs;
vector<int> primes;
void sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (int i = 2; i <= 32000; ++i) {
		if (bs[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= 32000; j += i) bs[j] = 0;
		}
	}
}*/
long long mp(long long b, long long e) {
	if (e == 0) return 1;
	long long a = mp(b, e >> 1);
	a = a * a % mod;
	if (e & 1) a = a * b % mod;
	return a;
}
int main() {
	int n;
	scanf("%d", &n);
	int a[2 * n];
	for (int i = 0; i < 2 * n; ++i) scanf("%d", &a[i]);
	sort(a, a + 2 * n);
	long long ans = 0, facn = 1, fac2n;
	for (int i = 0; i < n; ++i) ans -= a[i], facn = facn * (i + 1) % mod;
	fac2n = facn;
	for (int i = n; i < 2 * n; ++i) ans += a[i], fac2n = fac2n * (i + 1) % mod;
	ans %= mod;
	ans = ans * fac2n % mod * mp(facn, mod - 2) % mod * mp(facn, mod - 2) % mod;
	printf("%lld", ans);
	return 0;
	/*sieve();
	int t;
	scanf("%d", &t);
	printf("%d\n", primes.back());
	for (int h = 0; h < t; ++h) {
		long long p, q, lcd = 1000000001, ans;
		scanf("%lld %lld", &p, &q);
		ans = p;
		for (int i: primes) {
			int pp = 0, qq = 0;
			while (p % i == 0) ++pp, p /= i;
			while (q % i == 0) ++qq, q /= i;
			if (qq == 0) continue;
			long long fix = 1;
			for (int j = 0; j <= pp - qq; ++j) fix *= i;
			lcd = min(lcd, fix);
		}
		if (q != 1) {
			long long fix = 1;
			while (p % q == 0) fix *= q, p /= q;
			lcd = min(lcd, fix);
		}
		ans /= lcd;
		printf("%lld\n", ans);
	}
	return 0;*/
}