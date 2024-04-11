#include <bits/stdc++.h>
using namespace std;

main() {
	int v, sum, max1, max2, t, n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		sum = max1 = 0;
		while (n--) {
			scanf("%d", &v);
			sum += v;
			if (sum > max1)
				max1 = sum;
		}
		scanf("%d", &m);
		sum = max2 = 0;
		while (m--) {
			scanf("%d", &v);
			sum += v;
			if (sum > max2)
				max2 = sum;
		}
		printf("%d\n", max1 + max2);
	}
}