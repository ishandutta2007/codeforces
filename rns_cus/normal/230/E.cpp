#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, a[1001001];

int main() {
//	freopen("e.in", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d %d", &x, &y);
		a[x] ++, a[y] ++;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += 1ll * a[i] * (n - 1 - a[i]);
	}
	ans /= 2;
	ans = 1ll * n * (n - 1) * (n - 2) / 6 - ans;
	cout << ans << endl;
	return 0;
}