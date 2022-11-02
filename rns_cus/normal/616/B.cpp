#include <bits/stdc++.h>
using namespace std;

int n, m, x;

int main() {
//	freopen("b.in", "r", stdin);
	scanf("%d %d", &n, &m);
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int rlt = 2e9;
		for (int j = 1; j <= m; j ++) scanf("%d", &x), rlt = min(rlt, x);
		ans = max(ans, rlt);
	}
	printf("%d\n", ans);
	return 0;
}