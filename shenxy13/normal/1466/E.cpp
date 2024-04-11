#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const long long mod = 1000000007;
int main() {
	int t;
	scanf("%d", &t);
	for (int h = 0; h < t; ++h) {
		int n;
		scanf("%d", &n);
		long long x, ans = 0;
		bool bits[n][60];
		int ons[60];
		fill_n(ons, 60, 0);
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &x);
			for (int j = 0; j < 60; ++j) bits[i][j] = ((x & (1LL << j)) != 0);
			for (int j = 0; j < 60; ++j) ons[j] += bits[i][j];
		}
		for (int i = 0; i < n; ++i) {
			long long a = 0, o = 0;
			for (int j = 0; j < 60; ++j) {
				long long p2 = (1LL << j) % mod;
				if (bits[i][j]) {
					a = (a + ons[j] * p2 % mod) % mod;
					o = (o + n * p2 % mod) % mod;
				} else o = (o + ons[j] * p2 % mod) % mod;
			}
			ans = (ans + a * o % mod) % mod;
		}
		printf("%lld\n", ans % mod);
	}
	return 0;
}