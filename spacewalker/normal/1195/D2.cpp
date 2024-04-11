#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;

ll modexp(ll b, ll e) {
	if (e == 0) return 1;
	else return (e & 1 ? b : 1) * modexp(b * b % MOD, e / 2) % MOD;
}

ll digCount(ll x) {
	if (x < 10) return 1;
	else return 1 + digCount(x / 10);
}

vector<ll> dcGroup[11];

ll getEntangledSum(vector<ll> &a, vector<ll> &b) {
	ll ans = 0;
	int n = a.size(), m = b.size();
	for (int i = 0; i < m; ++i) {
		ll cdval = 1;
		ll cnum = b[i];
		while (cnum > 0) {
			ans = (ans + (cnum % 10 * cdval) % MOD * n) % MOD;
//			printf("b %d cnum %lld ans %lld\n", i, cnum, ans);
			cdval = (cdval * 100) % MOD;
			cnum /= 10;
		}
	}
	for (int i = 0; i < n; ++i) {
		ll cdval = 10;
		ll cnum = a[i];
		while (cnum > 0) {
			ans = (ans + (cnum % 10 * cdval) % MOD * m) % MOD;
//			printf("a %d cnum %lld ans %lld\n", i, cnum, ans);
			cdval = (cdval * 100) % MOD;
			cnum /= 10;
		}
	}
	return ans;
}

ll getFirstDigs(ll x, int toRem) {
	if (toRem == 0) return x;
	else return getFirstDigs(x / 10, toRem - 1);
}

ll getLastDigs(ll x, int toRem) {
	if (toRem == 0) return 0;
	else return (x % 10) + 10 * getLastDigs(x / 10, toRem - 1);
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x; scanf("%d", &x);
		dcGroup[digCount(x)].push_back(x);
	}
	ll ans = 0;
	for (int dci = 1; dci <= 10; ++dci) {
		for (int dcj = 1; dcj <= 10; ++dcj) {
			if (dcGroup[dci].size() == 0 || dcGroup[dcj].size() == 0) continue;
//			printf("%d vs %d\n", dci, dcj);
			int uci = dci, ucj = dcj;
			if (uci < ucj) swap(uci, ucj);
			vector<ll> group1 = dcGroup[uci], group2 = dcGroup[ucj];
			if (uci > ucj) {
				for (int i = 0; i < group1.size(); ++i) {
					ll extra = ((getFirstDigs(group1[i], ucj) * (ll)group2.size()) % MOD) % MOD;
//					printf("gelem %lld x %lld\n", group1[i], extra * modexp(10, 2 * ucj)) ; 
					ans = (ans + extra * modexp(10, 2 * ucj) % MOD) % MOD; 
					group1[i] = getLastDigs(group1[i], ucj);
//					printf("pruned %lld\n", group1[i]);
				}
			}
			if (dci >= dcj) ans = (ans + getEntangledSum(group1, group2)) % MOD;
			else ans = (ans + getEntangledSum(group2, group1)) % MOD;
//			printf("ans %lld\n", ans);
		}
	}
	printf("%lld\n", ans);
	return 0;
}