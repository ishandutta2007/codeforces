#include <bits/stdc++.h>
typedef long long ll;
const int N = 100000 + 10;

int main() {
	std::ios::sync_with_stdio(false);
	std::cout.tie(0);

	int n;
	std::cin >> n;

	std::vector<ll> a(n);
	for (int i = 0; i < n; i ++)
		std::cin >> a[i];
	std::sort(a.begin(), a.end());

	int m;
	std::cin >> m;
	ll x[m], y[m];
	for (int i = 0; i < m; i ++) 
		std::cin >> x[i] >> y[i];

	ll sum = std::accumulate(a.begin(), a.end(), 0ll);

	for (int i = 0; i < m; i ++) {
		ll ans = 2e18;
		auto it = std::lower_bound(a.begin(), a.end(), x[i]);
		if (it != a.end()) {
			ans = std::min(ans, std::max(y[i] - (sum - (*it)), 0ll));
		} 
		if (it != a.begin()){
			it --;
			ans = std::min(ans, x[i] - (*it) + std::max(y[i] - (sum - (*it)), 0ll));
		}
		std::cout << ans << "\n";
	}

}