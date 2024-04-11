#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr int INVMAX = 100;



ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

ll modinv(ll x) {
	return modexp(x, MOD - 2);
}

ll inverted[INVMAX];

ll choose(ll n, ll k) {
//	printf("choose %lld %lld\n", n, k);
//	printf("cterm %lld %lld\n", n, modinv(k));
	if (n < 0 || k < 0 || n < k) return 0;
	else if (k == 0) return 1;
	else return n % MOD * inverted[k] % MOD * choose(n - 1, k - 1) % MOD;
}

vector<ll> flow;

ll getScore(int etc, ll curFree) {
	if (etc == flow.size()) {
		return (choose(curFree + (ll)flow.size() - 1, (ll)flow.size() - 1));
	}
	ll ans = getScore(etc + 1, curFree) - getScore(etc + 1, curFree - flow[etc] - 1);
	return (ans % MOD + MOD) % MOD;	
}

int main() {
	for (int i = 1; i < INVMAX; ++i) inverted[i] = modinv(i);
	int n; ll s; scanf("%d %lld", &n, &s);
	flow = vector<ll>(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &flow[i]);
	printf("%lld\n", getScore(0, s));
	return 0;
}