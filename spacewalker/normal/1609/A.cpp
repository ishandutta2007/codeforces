#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		vector<ll> arr(n);
		ll pow2 = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", &arr[i]);
			while (arr[i] % 2 == 0) {
				arr[i] /= 2;
				pow2 *= 2;
			}
		}
		auto ij = max_element(begin(arr), end(arr));
		*ij *= pow2;
		ll ans = 0;
		for (ll v : arr) ans += v;
		printf("%lld\n", ans);
	}
}