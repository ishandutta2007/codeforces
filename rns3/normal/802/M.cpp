#include <bits/stdc++.h>
using namespace std;

#define N 2222

int n, k, a[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort (a + 1, a + n + 1);
	int ans = 0;
	for (int i = 1; i <= k; i ++) ans += a[i];
	printf("%d\n", ans);

	return 0;
}