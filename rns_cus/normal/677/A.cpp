#include <bits/stdc++.h>
using namespace std;

int n, h, m, ans;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &h);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &m);
		if (m > h) ans += 2;
		else ans ++;
	}
	printf("%d\n", ans);
	return 0;
}