#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;
constexpr int NMAX = 505;

int n, k;

ll FMOD(ll x) {
	return (x + MOD) % MOD;
}

ll intAnswers[NMAX][NMAX], psums[NMAX][NMAX], exact[NMAX][NMAX];

int main() {
	scanf("%d %d", &n, &k);
	for (int nBound = 1; nBound <= n; ++nBound) {
		intAnswers[nBound][0] = psums[nBound][0] = 1;
		for (int csum = 1; csum <= n; ++csum) {
			// take a sum from 
			int ql = max(0, csum - nBound), qr = csum - 1;
			intAnswers[nBound][csum] = FMOD(psums[nBound][qr] - (ql == 0 ? 0 : psums[nBound][ql - 1]));
			psums[nBound][csum] = (psums[nBound][csum-1] + intAnswers[nBound][csum]) % MOD;
			// printf("IA %d %d = %lld\n", nBound, csum, intAnswers[nBound][csum]);
		}
	}
	// printf("PHASE 2\n");
	for (int csum = 1; csum <= n; ++csum) {
		for (int nBound = n; nBound > 0; --nBound) {
			exact[nBound][csum] = FMOD(intAnswers[nBound][csum] - intAnswers[nBound-1][csum]);
		}
	}
	ll ans = 0;
	for (int max_a = 1; max_a <= n; ++max_a) {
		int max_b = min(n, k / max_a - (k % max_a == 0 ? 1 : 0));
		// printf("max_a and max_b = %d %d\n", max_a, max_b);
		if (max_b == 0) continue;
		ans = (ans + exact[max_a][n] * intAnswers[max_b][n] % MOD) % MOD;
	}
	printf("%lld\n", ans*2 % MOD);
	return 0;
}