#include <bits/stdc++.h>
using namespace std;

struct dt {
	int w, cnt;
} d[100005];

int cmp(dt a, dt b) {
	return a.w > b.w;
}

main() {
	int t, n, i, j, k, a, b, p;
	long long sum;
	scanf("%d", &t);
	while (t--) {
		memset(d, 0, sizeof(d));
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
			scanf("%d", &d[i].w);
		for (i = 0; i < n - 1; ++i) {
			scanf("%d%d", &a, &b);
			++d[a - 1].cnt;
			++d[b - 1].cnt;
		}
		sum = 0;
		for (i = 0; i < n; ++i)
			sum += d[i].w;
		printf("%lld", sum);
		sort(d, d + n, cmp);
		p = 0;
		for (i = 1; i < n - 1; ++i) {
			while (d[p].cnt <= 1)
				++p;
			sum += d[p].w;
			printf(" %lld", sum);
			--d[p].cnt;
		}
		printf("\n");
	}
}