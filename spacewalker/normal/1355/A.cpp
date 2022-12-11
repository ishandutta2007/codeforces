#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll a1, k; scanf("%lld %lld", &a1, &k);
		for (ll i = 1; i < k; ++i) {
			ll ac = a1;
			ll mid = 10, mad = 0;
			while (ac > 0) {
				mid = min(mid, ac % 10);
				mad = max(mad, ac % 10);
				ac /= 10;
			}
			if (mid == 0) break;
//			printf("%lld adding %d * %d\n", a1, mid, mad);
			a1 += mid * mad;
		}
		printf("%lld\n", a1);
	}
	return 0;
}