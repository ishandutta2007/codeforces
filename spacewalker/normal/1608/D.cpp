#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
constexpr int NMAX = 100010;

ll fact[NMAX], invfact[NMAX];

ll modexp(ll b, ll e = MOD - 2) {
	if (e == 0) return 1;
	else return (e % 2 == 0 ? 1 : b) * modexp(b * b % MOD, e / 2) % MOD;
}

ll comb(ll n, ll r) {
	if (r < 0 || r > n) return 0;
	else return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < NMAX; ++i) fact[i] = (fact[i-1] * i) % MOD;
	for (int i = 0; i < NMAX; ++i) invfact[i] = modexp(fact[i]);
	int n; scanf("%d", &n);
	vector<pair<char, char>> doms(n);
	static char cdom[5];
	for (int i = 0; i < n; ++i) {
		scanf("%s", cdom);
		doms[i].first = cdom[0];
		doms[i].second = cdom[1];
	}
	for (int i = 0; i < n; ++i) {
		if (doms[i].first == 'W') doms[i].first = 'B';
		else if (doms[i].first == 'B') doms[i].first = 'W';
	}
	int q1 = 0, w1 = 0, q2 = 0, w2 = 0;
	for (int i = 0; i < n; ++i) {
		if (doms[i].first == '?') ++q1;
		else if (doms[i].first == 'W') ++w1;

		if (doms[i].second == '?') ++q2;
		else if (doms[i].second == 'W') ++w2;
	}
	ll ans = 0;
	for (int wc = 0; wc <= n; ++wc) {
		if (wc < min(w1, w2)) continue;
		int nw1 = wc - w1, nw2 = wc - w2;
		ll ccontrib = comb(q1, nw1) * comb(q2, nw2) % MOD;
		// printf("wc %d %lld ways\n", wc, ccontrib);
		ans = (ans + ccontrib) % MOD;
	}
	// take out ways to assign such that all are WW or BB
	ll noSwitchWays = 1;
	for (int i = 0; i < n; ++i) {
		auto [c1, c2] = doms[i];
		if (c1 == '?' && c2 == '?') noSwitchWays = (noSwitchWays * 2) % MOD;
		else if (c1 != '?' & c2 != '?' && c1 != c2) noSwitchWays = 0;
	}
	// add back ways to assign such that all are WW or all are BB
	bool allWhite = true, allBlack = true;
	for (int i = 0; i < n; ++i) {
		auto [c1, c2] = doms[i];
		// printf("%d %c%c\n", i, c1, c2);
		if (c1 == 'W' || c2 == 'W') allBlack = false;
		if (c1 == 'B' || c2 == 'B') allWhite = false;
	}
	// printf("corrections %lld %d %d\n", noSwitchWays, int(allWhite), int(allBlack));
	printf("%lld\n", (ans - noSwitchWays + (int)(allWhite) + (int)allBlack + MOD) % MOD);
}