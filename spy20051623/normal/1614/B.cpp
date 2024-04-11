#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[200005];
int ans[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1, greater<pair<int, int>>());
	long long sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (i & 1) ans[a[i].second] = (i + 1) / 2, sum += 1ll * (i + 1) / 2 * a[i].first;
		else ans[a[i].second] = -i / 2, sum += 1ll * i / 2 * a[i].first;
	}
	printf("%lld\n", sum * 2);
	printf("0 ");
	for (int i = 1; i <= n; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
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