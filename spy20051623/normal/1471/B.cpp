#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];

main() {
	int t, n, i, j, min, mini;
	long long x, sum;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%lld", &n, &x);
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		min = 10000;
		mini = 0;
		for (i = 0; i < n; ++i) {
			scanf("%lld", &a[i]);
			j = a[i];
			while (j % x == 0) {
				++b[i];
				j /= x;
			}
			if (b[i] < min) {
				mini = i;
				min = b[i];
			}
		}
		sum = 0;
		for (i = 0; i < n; ++i) {
			if (i < mini)
				sum += (min + 2) * a[i];
			else
				sum += (min + 1) * a[i];
		}
		printf("%lld\n", sum);
	}
}