#include <bits/stdc++.h>
using namespace std;

int n, sum, a[111], vis[111];

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]), sum += a[i];
	sum /= (n / 2);
	for (int i = 1; i <= n; i ++) {
		if (vis[i]) continue;
		for (int j = i + 1; j <= n; j ++) {
			if (!vis[j] && a[i] + a[j] == sum) {
				vis[j] = 1;
				printf("%d %d\n", i, j);
				break;
			}
		}
	}
	return 0;
}