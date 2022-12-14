#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
const long long mod = 1000000007;
bool has_mod = false;
long long mp(long long b, long long e) {
	if (e == 0) return 1;
	long long a = mp(b, e / 2);
	a = a * a;
	if (a >= mod) a %= mod, has_mod = true;
	if (e & 1) a = a * b;
	if (a >= mod) a %= mod, has_mod = true;
	return a;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n, p;
		scanf("%d %d", &n, &p);
		int k[n];
		for (int i = 0; i < n; ++i) scanf("%d", &k[i]);
		if (p == 1) {
			printf("%d\n", n % 2);
			continue;
		}
		sort(k, k + n);
		long long ans = 0, diff = 0, pow = 1000000;
		bool term = false;
		for (int i = n - 1; i >= 0; --i) {
			if (term) {
				if (diff > 0) ans = (ans - mp(p, k[i])) % mod;
				else ans = (ans + mp(p, k[i])) % mod;
			} else if (diff == 0) pow = k[i], ++diff, ans = (ans + mp(p, k[i])) % mod;
			else if (pow != k[i]) {
				has_mod = false;
				long long x = mp(p, pow - k[i]);
				if (has_mod) {
					term = true;
					if (diff > 0) ans = (ans - mp(p, k[i])) % mod;
					else ans = (ans + mp(p, k[i])) % mod;
				} else {
					diff *= x;
					pow = k[i];
					if (diff > n) {
						term = true;
						if (diff > 0) ans = (ans - mp(p, k[i])) % mod;
						else ans = (ans + mp(p, k[i])) % mod;
					} else {
						if (diff > 0) --diff, ans = (ans - mp(p, k[i])) % mod;
						else ++diff, ans = (ans + mp(p, k[i])) % mod;
					}
				}
			} else {
				if (diff > 0) --diff, ans = (ans - mp(p, k[i])) % mod;
				else ++diff, ans = (ans + mp(p, k[i])) % mod;
			}
		}
		if (diff > 0) printf("%lld\n", (ans + mod) % mod);
		else printf("%lld\n", (mod - ans) % mod);
	}
	return 0;
}