#include <bits/stdc++.h>
using namespace std;

int n, m, ans;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= m; j ++) {
			if (i * i + j == n && i + j * j == m) ans ++;
		}
	}
	printf("%d\n", ans);
	return 0;
}