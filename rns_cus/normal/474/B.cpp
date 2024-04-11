#include <bits/stdc++.h>
using namespace std;

int n, q, x, a[100100];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &x), a[i] = a[i-1] + x;
	scanf("%d", &q);
	while (q --) {
		scanf("%d", &x);
		printf("%d\n", lower_bound(a + 1, a + n + 1, x) - a);
	}
	return 0;
}