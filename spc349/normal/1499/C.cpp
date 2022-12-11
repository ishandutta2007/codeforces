#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		long long minj[2] = {0x3f3f3f3f, a[1]}, sum[2] = {0, a[1]}, cnt[2] = {0, 1};
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 2; i <= n; i++) {
			minj[i & 1] = min(minj[i & 1], (long long)a[i]), sum[i & 1] += a[i], cnt[i & 1]++;
			ans = min(ans, sum[0] + sum[1] + minj[0] * (n - cnt[0]) + minj[1] * (n - cnt[1]));
		}
		printf("%I64d\n", ans);
	}
	return 0;
}