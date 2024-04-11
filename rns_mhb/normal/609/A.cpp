#include <bits/stdc++.h>
using namespace std;

int a[111];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	int ans = 0, now = 0;
	while (now < m) now += a[++ans];
	printf("%d\n", ans);

	return 0;
}