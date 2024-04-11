#include <bits/stdc++.h>

using namespace std;

const int d[] = {1, 10, (int) 1e2, (int) 1e3, (int) 1e4, (int) 1e5, (int) 1e6, (int) 1e7, (int) 1e8, (int) 1e9};
int a[15];

void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	++k;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n - 1; ++i) {
		long long lim = min(d[a[i + 1] - a[i]] - 1, k);
		ans += lim * d[a[i]];
		k -= lim;
	}
	ans += 1ll * k * d[a[n - 1]];
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