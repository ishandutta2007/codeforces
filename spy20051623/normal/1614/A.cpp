#include <bits/stdc++.h>

using namespace std;

int a[1000];

void solve() {
	int n, l, r, k;
	scanf("%d%d%d%d", &n, &l, &r, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int x = lower_bound(a, a + n, l) - a, y = upper_bound(a, a + n, r) - a - 1;
	int ans = 0;
	for (int i = x; i <= y; ++i) {
		if (k >= a[i]) ++ans, k -= a[i];
	}
	printf("%d\n", ans);
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