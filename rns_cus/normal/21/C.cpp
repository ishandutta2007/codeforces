#include <bits/stdc++.h>
using namespace std;
#define N 100100

int n, m, k, x, a[N], b[N], c[N];

int main() {
//	freopen("c.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &x);
		a[i] = a[i-1] + x;
	}
	if (a[n] % 3) {
		puts("0"); return 0;
	}
	int sum = a[n] / 3;
	for (int i = 1; i < n; i ++) {
		if (a[i] == sum) b[m++] = i;
		if (a[i] == sum * 2) c[k++] = i;
	}
	if (!m || !k) {
		puts("0"); return 0;
	}
	long long ans = 0;
	for (int i = 0; i < m; i ++) {
		x = lower_bound(c, c + k, b[i] + 1) - c;
		ans += k - x;
	}
	printf("%I64d\n", ans);
	return 0;
}