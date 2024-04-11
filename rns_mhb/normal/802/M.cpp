#include <bits/stdc++.h>
using namespace std;

int a[10101], n, k;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= k; i ++) ans += a[i];
	printf("%d\n", ans);

	return 0;
}