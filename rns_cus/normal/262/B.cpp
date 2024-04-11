#include <bits/stdc++.h>
using namespace std;

int n, k, ans, a[100100];

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i ++) if (k) {
		if (a[i] < 0) a[i] = -a[i], k --;
	}
	if (!k) {
		for (int i = 0; i < n; i ++) ans += a[i];
	}
	else {
		sort(a, a + n);
		for (int i = 0; i < n; i ++) ans += a[i];
		if (k & 1) ans -= a[0] * 2;
	}
	printf("%d\n", ans);
	return 0;
}