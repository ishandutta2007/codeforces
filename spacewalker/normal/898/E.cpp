#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll ceilSq(ll x) {
	// nnnnnnyyyyyyyyy
	ll lo = 0;
	ll hi = 1000000;
	while (lo < hi) {
		ll mid = (lo + hi) / 2;
		if (mid * mid >= x) hi = mid;
		else lo = mid + 1;
	}
	return lo;
}

int main() {
	int n; scanf("%d", &n);
	vector<ll> arr(n);
	for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
	vector<ll> distToSq(n);
	ll squares = 0;
	for (int i = 0; i < n; ++i) {
		ll est = ceilSq(arr[i]);
		// printf("%d est %lld\n", i, est);
		distToSq[i] = min(abs(est * est - arr[i]), abs(arr[i] - (est - 1) * (est - 1)));
		if (distToSq[i] == 0) ++squares;
	}
	if (squares <= n/2) {
		sort(distToSq.begin(), distToSq.end());
		ll ans = 0;
		for (int i = 0; i < n/2; ++i) ans += distToSq[i];
		printf("%lld\n", ans);	
	} else {
		ll oneAdd = 0, twoAdd = 0;
		for (int i = 0; i < n; ++i) {
			if (distToSq[i] == 0) {
				if (arr[i] == 0) ++twoAdd;
				else ++oneAdd;
			}
		}
		ll ans = 0;
		while (oneAdd + twoAdd != n/2) {
			if (oneAdd > 0) {
				++ans; --oneAdd;
			} else {
				ans += 2; --twoAdd;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}