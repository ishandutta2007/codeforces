#include <bits/stdc++.h>
using namespace std;

int n, k, a[1001001];

int main() {
//	freopen("m.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	long long ans = 0;
	for (int i = 1; i <= k; i ++) ans += a[i];
	printf("%I64d\n", ans);
	return 0;
}