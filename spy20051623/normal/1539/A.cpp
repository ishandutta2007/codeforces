#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, x, t;
	scanf("%d%d%d", &n, &x, &t);
	int m = t / x;
	long long ans = 0;
	if (n <= m) {
		ans = 1LL * n * (n - 1) / 2;
	} else {
		ans = 1LL * m * (m - 1) / 2 + 1LL * m * (n - m);
	}
	printf("%lld\n", ans);
}

int main() {
//	freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}