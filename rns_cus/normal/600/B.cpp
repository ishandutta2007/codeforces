#include <bits/stdc++.h>
using namespace std;

int n, m, a[200100], x;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	while (m --) {
		scanf("%d", &x);
		int k = lower_bound(a + 1, a + n + 1, x + 1) - a - 1;
		printf("%d ", k);
	}
	return 0;
}