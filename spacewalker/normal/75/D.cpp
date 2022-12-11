#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<vector<ll>> pieces(n);
	for (int i = 0; i < n; ++i) {
		int l; scanf("%d", &l);
		pieces[i] = vector<ll>(l);
		for (int j = 0; j < l; ++j) scanf("%lld", &pieces[i][j]);
	}
	vector<ll> bestPrefix(n), arrSum(n), bestArr(n), bestSuffix(n);
	for (int i = 0; i < n; ++i) {
		// printf("PROC ARR %d bp start %lld\n", i, pieces[i][0]);
		vector<ll> cSumAt(pieces[i].size(), 0);
		bestPrefix[i] = pieces[i][0];
		for (int j = 0; j < pieces[i].size(); ++j) {
			arrSum[i] += pieces[i][j];
			bestPrefix[i] = max(bestPrefix[i], arrSum[i]);
			cSumAt[j] = (j > 0 ? max(cSumAt[j-1], 0LL) : 0) + pieces[i][j];
			// printf("AFTER %d: sum %lld bp %lld csa %lld\n", j, arrSum[i], bestPrefix[i], cSumAt[j]);
		}
		bestSuffix[i] = cSumAt.back();
		bestArr[i] = *max_element(cSumAt.begin(), cSumAt.end());
		// printf("best elem %lld\n", bestArr[i]);
	}
	ll ans = -1000000000000000000;
	vector<ll> ansEndingAt(m);
	for (int i = 0; i < m; ++i) {
		int k; scanf("%d", &k); --k;
		ansEndingAt[i] = max(arrSum[k] + (i > 0 ? max(ansEndingAt[i-1], 0LL) : 0), bestSuffix[k]);
		ans = max(max(ans, bestArr[k]), (i > 0 ? max(ansEndingAt[i-1], 0LL) : 0) + bestPrefix[k]);
	}
	printf("%lld\n", ans);
	return 0;
}