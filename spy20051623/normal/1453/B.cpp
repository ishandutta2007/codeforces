#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (i)
			ans += abs(a[i] - a[i - 1]);
	}
	int maxm = 0;
	maxm = max(maxm, abs(a[0] - a[1]));
	maxm = max(maxm, abs(a[n - 1] - a[n - 2]));
	for (int i = 1; i < n - 1; ++i) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			maxm = max(maxm, 2 * (a[i] - max(a[i - 1], a[i + 1])));
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			maxm = max(maxm, 2 * (min(a[i - 1], a[i + 1]) - a[i]));
	}
	ans -= maxm;
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