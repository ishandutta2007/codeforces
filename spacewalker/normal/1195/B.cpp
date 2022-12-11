#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
	int n, k; scanf("%d %d", &n, &k);
	for (ll fct = 1;; ++fct) {
		ll tcan = fct * (fct + 1) / 2;
		if (tcan >= k && fct + (tcan - k) == n) {
			
			printf("%lld\n", tcan - k);
			return 0;
		}
	}
	return 0;
}