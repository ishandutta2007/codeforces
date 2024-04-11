#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <utility>
#include <cmath>

using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;
constexpr ll NMAX = 1000010;
ll fact[NMAX];

ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e % 2 == 1 ? b : 1) * modexp(b*b%MOD, e/2) % MOD;
}

ll modinv(ll x) {
	return modexp(x, MOD - 2);
}

ll permute(ll n, ll k) {
	return fact[n] * modinv(fact[k]) % MOD;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < NMAX; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
	}
	int n; scanf("%d", &n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	vector<ll> exCounts(n+1);
	exCounts[1] = n;
	for (int i = 2; i < n; ++i) {
		exCounts[i] = (permute(n, n-i) - permute(n, n-i+1) + MOD) % MOD;
		// printf("exc %d %lld\n", i, exCounts[i]);
	}
	ll ans = 0;
	for (int i = 1; i < n; ++i) {
		ans = (ans + i * exCounts[i] % MOD) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}