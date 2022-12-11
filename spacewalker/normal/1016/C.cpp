#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

ll shroom[2][300010], prefixSums[2][300010], suffixSums[2][300010], incRun[2][300010], decRun[2][300010];

int main() {
	int n; scanf("%d", &n);
	for (int r = 0; r < 2; ++r) {
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &shroom[r][i]);
		}
	}
	for (int r = 0; r < 2; ++r) {
		prefixSums[r][0] = shroom[r][0];
		suffixSums[r][n-1] = shroom[r][n-1];
		for (int i = 1; i < n; ++i) prefixSums[r][i] = prefixSums[r][i-1] + shroom[r][i];
		for (int i = n - 2; i >= 0; --i) suffixSums[r][i] = suffixSums[r][i+1] + shroom[r][i];
		incRun[r][n-1] = decRun[r][n-1] = shroom[r][n-1];
		for (int i = n - 2; i >= 0; --i) {
			incRun[r][i] = incRun[r][i+1] + suffixSums[r][i];
			decRun[r][i] = decRun[r][i+1] + (n-i)*shroom[r][i];
		}
	}

	ll initRun = incRun[0][0] - prefixSums[0][n-1] + (n-1)*prefixSums[1][n-1] + decRun[1][0];
	ll lsrunscore = 0;
	for (ll i = 0, startRow = 0; i < n; ++i, startRow ^= 1) {
		lsrunscore += (2*i)*shroom[startRow][i] + (2*i+1)*shroom[startRow^1][i];
		// printf("at i = %lld, inr = %lld, lssc = %lld\n", i, initRun, lsrunscore);
		ll rsrunscore = (i == n - 1 ? 0 : (incRun[startRow^1][i+1] + (2*i+1)*suffixSums[startRow^1][i+1] + 
			(n+i)*suffixSums[startRow][i+1] + decRun[startRow][i+1]));
		// if (i < n - 1) printf("rsc = %lld %lld %lld\n", rsrunscore, (n+i)*suffixSums[startRow^1][i+1], decRun[startRow^1][i+1]);
		initRun = max(initRun, lsrunscore + rsrunscore);
	}
	printf("%lld\n", initRun);
	return 0;
}