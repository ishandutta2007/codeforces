#include <bits/stdc++.h>

using namespace std;

pair<int, int> p[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i].first);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i].second);
	}
	p[n] = {0, 0};
	sort(p, p + n, greater<pair<int, int>>());
	long long sum = 0, ans = 1e18;
	for (int i = 0; i <= n; ++i) {
		ans = min(ans, max(sum, (long long) p[i].first));
		sum += p[i].second;
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