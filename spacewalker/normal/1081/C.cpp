#include <cstdio>

typedef long long ll;
constexpr ll mod = 998244353;

ll ct[2010][2010];

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	// ct[i][j] = how many ways to color first i elements with k switches?
	// note: last color is fixed to be color 1
	ct[1][0] = 1;
	for (int i = 2; i <= n; ++i) {
		// without switches; only 1 way
		ct[i][0] = 1;
		for (int sw = 1; sw <= i - 1; ++sw) {
			// with sw switches:
			// either we switch on this one = (m-1)*
			// or we don't. so equal to ct[i-1][j]
			ct[i][sw] = ((m-1)*ct[i-1][sw-1] + ct[i-1][sw]) % mod;
		}
	}
	printf("%lld\n", (ct[n][k] * m) % mod);
	return 0;
}