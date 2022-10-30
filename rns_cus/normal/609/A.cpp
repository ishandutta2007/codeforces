#include <bits/stdc++.h>
using namespace std;

int n, m, a[100100];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) {
		m -= a[i];
		if (m <= 0) {
			printf("%d\n", i); return 0;
		}
	}
	return 0;
}