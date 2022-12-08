#include <bits/stdc++.h>

using namespace std;

int a[100005];
int b[100005];
long long sa[100005];
long long sb[100005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &b[i]);
	}
	sa[n + 1] = sb[0] = 0;
	long long ans = 1e18;
	for (int i = n; i >= 1; --i) {
		sa[i] = sa[i + 1] + a[i];
	}
	for (int i = 1; i <= n; ++i) {
		sb[i] = sb[i - 1] + b[i];
	}
	for (int i = 1; i <= n; ++i) {
		ans = min(ans, max(sa[i + 1], sb[i - 1]));
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