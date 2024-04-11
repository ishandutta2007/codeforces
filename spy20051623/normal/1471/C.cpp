#include <bits/stdc++.h>
using namespace std;
long long k[300005], c[300005];

main() {
	int t, n, m, i, j;
	long long sum;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; ++i) {
			scanf("%lld", &k[i]);
		}
		for (i = 0; i < m; ++i) {
			scanf("%lld", &c[i]);
		}
		sort(k, k + n);
		i = n - 1;
		j = 0;
		sum = 0;
		while (c[k[i] - 1] > c[j] && j < m && j < k[i] - 1 && i >= 0) {
			sum += c[j];
			--i;
			++j;
		}
		while (i >= 0) {
			sum += c[k[i] - 1];
			--i;
		}
		printf("%lld\n", sum);
	}
}