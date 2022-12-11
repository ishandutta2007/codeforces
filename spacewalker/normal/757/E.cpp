#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int NMAX = 1000010;
constexpr int EMAX = 50;
constexpr ll MOD = 1000000007;

int partSums[EMAX][NMAX];

int pFactor[NMAX];

int main() {
	partSums[0][0] = 1;
	for (int i = 1; i < EMAX; ++i) partSums[i][0] = 2;
	for (int i = 1; i < NMAX; ++i) {
		partSums[0][i] = 1;
		for (int j = 1; j < EMAX; ++j) partSums[j][i] = (partSums[j-1][i] + partSums[j][i-1]) % MOD;
	}
	for (int i = 0; i < NMAX; ++i) pFactor[i] = i;
	pFactor[0] = pFactor[1] = -1;
	for (int i = 2; i < NMAX; ++i) {
		if (pFactor[i] < i) continue;
		for (int toMark = 2 * i; toMark < NMAX; toMark += i) {
			pFactor[toMark] = i;
		}
	}
	int t; scanf("%d", &t);
	while (t--) {
		int r, n; scanf("%d %d", &r, &n);
		map<int, int> factors;
		while (n > 1) {
			++factors[pFactor[n]];
			n /= pFactor[n];
		}
		ll ans = 1;
		for (auto p_e : factors) {
//			printf("factor %d %d value %lld\n", p_e.second, r, partSums[p_e.second][r]);
			ans = (ans * partSums[p_e.second][r]) % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}