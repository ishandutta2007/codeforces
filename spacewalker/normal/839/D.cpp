#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int NMAX = 1000010;

vector<int> divisors[NMAX];

int dCount[NMAX];
ll gcdFreq[NMAX], pow2[NMAX], elemAns[NMAX];

int main() {
	memset(elemAns, -1, sizeof elemAns);
	pow2[0] = 1;
	for (int i = 1; i < NMAX; ++i) {
		pow2[i] = pow2[i-1] * 2 % MOD;
		for (int j = i; j < NMAX; j += i) if (i > 1) divisors[j].push_back(i);
	}
	// printf("PREPRO FINISHED\n");
	int n; scanf("%d", &n);
	vector<int> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		for (int div : divisors[arr[i]]) ++dCount[div];
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		// printf("testing %d with %lu divs\n", i, divisors[i].size());
		// for each divisor, in descending order:
		if (elemAns[arr[i]] != -1) {
			ans = (ans + elemAns[arr[i]]) % MOD;
			continue;
		}
		int idc = divisors[arr[i]].size();
		for (int j = idc - 1; j >= 0; --j) {
			int cdiv = divisors[arr[i]][j];
			gcdFreq[cdiv] = pow2[dCount[cdiv] - 1];
			for (int k = j + 1; k < idc; ++k) {
				if (divisors[arr[i]][k] % cdiv == 0) {
					gcdFreq[cdiv] -= gcdFreq[divisors[arr[i]][k]];
				}
			}
			gcdFreq[cdiv] %= MOD;
			// printf("%lld sets include %d and have gcd %d\n", gcdFreq[cdiv], i, cdiv);
		}
		int espans = 0;
		for (int div : divisors[arr[i]]) {
			espans = (espans + gcdFreq[div] * div) % MOD;
			gcdFreq[div] = 0;
		}
		ans = (ans + (elemAns[arr[i]] = espans)) % MOD;
	}
	printf("%lld\n", (ans + MOD) % MOD);
	return 0;
}