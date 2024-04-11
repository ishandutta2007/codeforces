#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
//	freopen("a.in", "r", stdin);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		long long ans = 1ll * n * (n + 1) / 2;
		for (int i = 0; i <= 30; i ++) if ((1 << i) <= n) ans -= 1 << i + 1;
		cout << ans << endl;
	}
	return 0;
}