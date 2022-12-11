#include <bits/stdc++.h>
using namespace std;
int main () {
	int n, q; scanf("%d%d", &n, &q);
	int c1 = n + 1 >> 1, c2 = n >> 1;
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		long long ans = 0;
		if (x + y & 1) {
			swap(c1, c2);
			ans = 1ll * c1 * (x >> 1) + 1ll * c2 * (x - 1 >> 1) + (y + 1 >> 1) + (1ll * n * n + 1) / 2;
			swap(c1, c2);
		} else ans = 1ll * c1 * (x >> 1) + 1ll * c2 * (x - 1 >> 1) + (y + 1 >> 1);
		printf("%I64d\n", ans);
	}
	return 0;
}