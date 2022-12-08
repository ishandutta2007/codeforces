#include <bits/stdc++.h>
using namespace std;

main() {
	int t, n, i, a;
	long long sum, m, x;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &x);
		m = sum = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a);
			if (a % x == 0)
				m += a / x;
			else
				m += a / x + 1;
			sum += a;
		}
		if (sum % x == 0)
			printf("%lld ", sum / x);
		else
			printf("%lld ", sum / x + 1);
		printf("%lld\n", m);
	}
}