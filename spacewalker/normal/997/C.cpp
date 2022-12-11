#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr ll M_MINUSONE = 998244352;
constexpr int NMAX = 1000010;

ll fact[NMAX], invfact[NMAX];

ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e & 1 ? b : 1) * modexp(b * b % MOD, e/2) % MOD;
}

ll binom(ll n, ll k) {
	return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main() {
	ll n; scanf("%lld", &n);
	fact[0] = 1;
	for (int i = 1; i < NMAX; ++i) fact[i] = fact[i-1] * i % MOD;
	invfact[NMAX - 1] = modexp(fact[NMAX - 1], MOD - 2);
	for (int i = NMAX - 2; i >= 0; --i) invfact[i] = invfact[i + 1] * (i + 1) % MOD;
	ll rowLuck = 0;
	for (int sameRow = 1; sameRow <= n; ++sameRow) {
		rowLuck = (rowLuck + (sameRow % 2 == 1 ? 1 : M_MINUSONE) * binom(n, sameRow) % MOD
				* modexp(3, n * (n - sameRow) + sameRow) % MOD) % MOD;
//		printf("cterm is %lld %lld\n", binom(n, sameRow), modexp(3, n * (n - sameRow) + sameRow));
//		printf("after sr %d rl is %lld\n", sameRow, rowLuck);
	}
	ll sharedSum = 0;
	for (int rc = 0; rc <= n - 1; ++rc) {
		ll negPowerA = M_MINUSONE * modexp(3, rc) % MOD;
		ll bSumStep = (modexp(1 + negPowerA, n) - modexp(negPowerA, n) + MOD) % MOD;
		sharedSum = (sharedSum + (rc % 2 == 0 ? 1 : M_MINUSONE) * binom(n, rc) % MOD
					* bSumStep % MOD) % MOD;
	}
//	printf("RL SS %lld %lld\n", rowLuck, sharedSum);
	sharedSum = (MOD - 3) * sharedSum % MOD;
	printf("%lld\n", (rowLuck * 2 + sharedSum) % MOD);
	return 0;
}