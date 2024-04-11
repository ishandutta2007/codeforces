#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1000000007;
constexpr int NMAX = 1000100;

ll fact[NMAX], invfact[NMAX];

ll modexp(ll b, ll e = MOD - 2) {
	if (e == 0) return 1;
	return (e & 1 ? b : 1) * modexp((b * b) % MOD, e/2) % MOD;
}

ll binom(int n, int r) {
	if (r < 0 || n < 0 || r > n) return 0;
	else return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

ll solve(ll n, ll m, ll k) {
	int subs = n - m;
	if (subs == 0) {
		return (n * k) % MOD;
	}
	ll ans = 0;
	for (int zeroSubTurn = n - subs; zeroSubTurn >= 0; --zeroSubTurn) {
		ll subWays = binom(n - zeroSubTurn - 1, subs - 1);
		ll zsValue = zeroSubTurn * k % MOD;
		// printf("zst %d %lld %lld over 2^%lld\n", zeroSubTurn, subWays, zsValue, n - zeroSubTurn);
		ll ccont = subWays * zsValue % MOD * modexp(modexp(2, n - zeroSubTurn));
		ans = (ans + ccont) % MOD;
	}
	return ans;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
	invfact[NMAX - 1] = modexp(fact[NMAX - 1]);
	for (int i = NMAX - 2; i >= 0; --i) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
	int t; scanf("%d", &t);
	while (t--) {
		int n, m, k; scanf("%d %d %d", &n, &m, &k);
		printf("%lld\n", solve(n, m, k));
	}
}