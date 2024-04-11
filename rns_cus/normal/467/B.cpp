#include <bits/stdc++.h>
using namespace std;

int n, m, k, x[1010], ans;

bool ok(int x, int y) {
	int dif = 0;
	for (int i = 0; i < n; i ++) {
		if ((x & 1) != (y & 1)) dif ++;
		x >>= 1, y >>= 1;
	}
	return dif <= k;
}

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m + 1; i ++) scanf("%d", &x[i]);
	for (int i = 1; i <= m; i ++) if (ok(x[i], x[m+1])) ans ++;
	printf("%d\n", ans);
	return 0;
}