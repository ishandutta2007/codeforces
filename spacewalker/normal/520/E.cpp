#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int NMAX = 100010;

char number[NMAX];

ll fact[NMAX];
ll pow10[NMAX];
ll invfact[NMAX];

ll choose(int n, int k) {
	if (k < 0 || k > n || n < 0) return 0;
	return fact[n] * invfact[k] % MOD * invfact[n-k] % MOD;
}

int main() {
	fact[0] = pow10[0] = 1;
	for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
	for (int i = 1; i < NMAX; ++i) pow10[i] = (pow10[i-1] * 10) % MOD;
	invfact[NMAX - 1] = 549915853;
	for (int i = NMAX - 2; i >= 0; --i) invfact[i] = (invfact[i+1] * (i+1)) % MOD;
	int n, k; scanf("%d %d", &n, &k);
	scanf("%s", number);
	for (int i = 0; i < n; ++i) number[i] -= '0';
	if (k == 0) {
		ll ans = 0;
		for (int i = n - 1; i >= 0; --i) ans = (ans + pow10[n - 1 - i] * number[i] % MOD) % MOD;
		printf("%lld\n", ans);
		return 0;
	}
	vector<ll> posCount(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		// fix this number of digits after the current digit
		posCount[i] = choose(n - i - 2, k - 1);	
//		printf("posCount %d %lld\n", i, posCount[i]);
	}
	vector<ll> withMaxAfterDig = posCount;
	for (int i = 1; i < n - 1; ++i) {
		withMaxAfterDig[i] = (pow10[i] * withMaxAfterDig[i] % MOD + withMaxAfterDig[i-1]) % MOD;	
	}
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		ans = (ans + choose(i, k) * pow10[n-1-i] % MOD * number[i] % MOD);	
	}
	for (int i = n - 2; i >= 0; --i) {
		ans = (ans + withMaxAfterDig[n-2-i] * number[i]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}