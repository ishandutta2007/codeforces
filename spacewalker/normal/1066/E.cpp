#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;
constexpr int NMAX = 200010;
ll pow2[200010], sSums[200010];

char nst[200010], mst[200010];

int main() {
	pow2[0] = 1;
	for (int i = 1; i < NMAX; ++i) {
		pow2[i] = (pow2[i-1] << 1) % MOD;
	}
	int n, m; scanf("%d %d", &n, &m);
	scanf("%s", nst + max(n, m) - n);
	scanf("%s", mst + max(n, m) - m);
	n = m = max(n, m);
	for (int i = n-1; i >= 0; --i) {
		// printf("chr %d = %c\n", i, nst[i]);
		sSums[i] = (sSums[i+1] + (nst[i] == '1' ? pow2[n-1-i] : 0)) % MOD;
		// printf("ss = %lld\n", sSums[i]);
	}
	ll ans = 0;
	for (int i = 0; i < m; ++i) {
		// printf("CHR %d = %c\n", i, mst[i]);
		if (mst[i] == '1') {
			ans = (ans + sSums[i]) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}