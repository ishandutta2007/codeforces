#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		ll sum = 0, ncsum = 0;
		for (int i = 0; i < n; ++i) {
			ll a; scanf("%lld", &a);
			sum += a, ncsum ^= a;
		}
		printf("2\n%lld %lld\n", ncsum, sum + ncsum);
	}
	return 0;
}