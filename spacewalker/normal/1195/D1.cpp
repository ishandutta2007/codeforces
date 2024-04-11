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

vector<int> dcGroup[11];

ll getEntangledSum(vector<int> &a, vector<int> &b) {
	ll ans = 0;
	int n = a.size(), m = b.size();
	for (int i = 0; i < m; ++i) {
		ll cdval = 1;
		ll cnum = b[i];
		while (cnum > 0) {
			ans = (ans + (cnum % 10 * cdval) % MOD * n) % MOD;
			cdval = (cdval * 100) % MOD;
			cnum /= 10;
		}
	}
	for (int i = 0; i < n; ++i) {
		ll cdval = 10;
		ll cnum = a[i];
		while (cnum > 0) {
			ans = (ans + (cnum % 10 * cdval) % MOD * m) % MOD;
			cdval = (cdval * 100) % MOD;
			cnum /= 10;
		}
	}
	return ans;
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
			if (dci == dcj) ans = (ans + getEntangledSum(dcGroup[dci], dcGroup[dcj])) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}