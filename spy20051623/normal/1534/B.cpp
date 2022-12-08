#include <bits/stdc++.h>

using namespace std;

long long a[400005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", &a[i]);
	}
	a[n+1]=0;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			ans += a[i] - max(a[i - 1], a[i + 1]);
			a[i] = max(a[i - 1], a[i + 1]);
		}
	}
	for (int i = 0; i < n + 1; ++i) {
		ans += abs(a[i] - a[i + 1]);
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