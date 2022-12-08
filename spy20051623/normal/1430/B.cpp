#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n, greater<int>());
	long long ans = 0;
	for (int i = 0; i < m + 1; ++i) {
		ans += a[i];
	}
	printf("%lld\n", ans);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
	return 0;
}