#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d %d", &a, &b);
		if (b >= a + 2) ans ++;
	}
	printf("%d\n", ans);
	return 0;
}