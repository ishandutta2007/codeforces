#include <stdio.h>

#define N 100100

int n, a[N], sum[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum[i] = sum[i-1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int x = sum[i], c = a[i+1], y = sum[n] - x - c;
		if (x <= y && x + c >= y) {ans = i + 1; break;}
		else if (x > y) {ans = i; break;}
	}
	printf("%d %d\n", ans, n - ans);
	return 0;
}