#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ceil(ll p, ll q) {
	return p/q + (p % q != 0);
}

int getRangeCount(vector<ll> &a, ll start, ll rStart, ll rEnd) {
	auto prStart = lower_bound(a.begin() + start, a.end(), rStart);
	auto prEnd = upper_bound(a.begin() + start, a.end(), rEnd);
	return max(0, int(prEnd - prStart));
}

int main() {
	ll n, x, k; scanf("%lld %lld %lld", &n, &x, &k);
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
	sort(a.begin(), a.end());
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		ll rs, re;
		if (k == 0) {
			if (a[i] % x == 0) continue;
			rs = a[i]; re = ceil(a[i], x)*x-1;
		} else {
			rs = ceil(a[i], x) * x + (k-1)*x;
			re = rs + x - 1;
		}
		rs = max(rs, a[i] + 1);
		// printf("%d range %lld %lld\n", i, rs, re);
		ans += getRangeCount(a, i, rs, re);
	}
	map<ll, ll> parts;
	for (ll v : a) ++parts[v];
	for (auto pp : parts) {
		if ((k == 0 && pp.first % x != 0) || (k == 1 && pp.first % x == 0)) {
			ans += pp.second * pp.second;
		}
	}
	printf("%lld\n", ans);
	return 0;
}