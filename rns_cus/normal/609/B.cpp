#include <bits/stdc++.h>
using namespace std;

int n, m, a[101];
long long sum1, sum2;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		int x;
		scanf("%d", &x);
		a[x] ++;
	}
	for (int i = 1; i <= m; i ++) sum1 += a[i], sum2 += 1ll * a[i] * a[i];
	printf("%I64d\n", (sum1 * sum1 - sum2) / 2);
	return 0;
}