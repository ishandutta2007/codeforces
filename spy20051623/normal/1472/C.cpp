#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];

main() {
	int i, t, n, max;
	scanf("%d", &t);
	while (t--) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		scanf("%d", &n);
		max = 0;
		for (i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		for (i = 0; i < n; ++i) {
			if (i + a[i] < n) {
				if (b[i] + a[i] > b[i + a[i]])
					b[i + a[i]] = b[i] + a[i];
			} else if (b[i] + a[i] > max)
				max = b[i] + a[i];
		}
		printf("%d\n", max);
	}
}