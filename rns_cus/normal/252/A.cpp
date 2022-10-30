#include <bits/stdc++.h>
using namespace std;

int n, a[1010];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int rlt = 0;
		for (int j = i; j <= n; j ++) rlt ^= a[j], ans = max(ans, rlt);
	}
	printf("%d\n", ans);
	return 0;
}