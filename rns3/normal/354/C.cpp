#include <bits/stdc++.h>
using namespace std;

#define N 300030
const int RT = 100;

int n, a[N], k, aa[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &aa[i]);
	sort (aa + 1, aa + n + 1);
	int e = 1;
	a[1] = aa[1];
	for (int i = 2; i <= n; i ++) if (aa[i] > aa[i-1]) a[++e] = aa[i];
	if (a[1] <= k + 1) {
		printf("%d\n", a[1]);
		return 0;
	}
	n = e;
	a[n+1] = 1e9;
	if (k > RT) {
		int ans = a[1] + 1, j;
		bool tag = 1;
		while (tag) {
			ans --;
			tag = 0;
			for (int now = 2 * ans; now <= a[n] + ans && !tag; now += ans) {
				j = lower_bound(a, a + n + 2, now) - a - 1;
				if (j && (a[j] % ans > k)) tag = 1;
			}
		}
		printf("%d\n", ans);
	}
	else {
        int ans = a[1] + 1;
        bool tag = 1;
        while (tag) {
			ans --;
			tag = 0;
			for (int i = 1; i <= n && !tag; i ++) if (a[i] % ans > k) tag = 1;
        }
        printf("%d\n", ans);
	}
	return 0;
}