#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		ll n, k; scanf("%lld %lld", &n, &k);
		// find the first i such that 1 + ... + i >= k
		ll lo = 1, hi = n - 1;
		while (lo < hi) {
			ll mid = (lo + hi) / 2;
			if (mid * (mid + 1) / 2 >= k) hi = mid;
			else lo = mid + 1;
		}
		ll minSumTaker = lo * (lo + 1) / 2;
		int b1 = n - 1 - lo, b2 = b1 + 1 + (minSumTaker - k);
		for (int i = 0; i < n; ++i) {
			if (i == b1 || i == b2) printf("b");
			else printf("a");
		}
		printf("\n");
	}
	return 0;
}