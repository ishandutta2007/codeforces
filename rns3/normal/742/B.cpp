#include <stdio.h>

#define N 100010

int main() {
	int n, x, vis[N] = {0}, t;
	long long ans = 0;
	scanf("%d %d", &n, &x);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &t);
		vis[t] ++;
	}
	if (x) for (int i = 0, j; i < N; i ++) {
		j = x ^ i;
		if (j < N) ans += 1ll * vis[i] * vis[j];
	}
	else for (int i = 0; i < N; i ++) {
		ans += 1ll * vis[i] * (vis[i] - 1);
	}
	printf("%I64d\n", ans / 2);
	return 0;
}