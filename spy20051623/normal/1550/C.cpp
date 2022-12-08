#include <bits/stdc++.h>

using namespace std;

int a[200005];

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		++ans;
		if (i < n - 1)++ans;
		if (i < n - 2 && 1ll * (a[i + 1] - a[i]) * (a[i + 1] - a[i + 2]) > 0)++ans;
		else continue;
		if (i < n - 3 && 1ll * (a[i + 1] - a[i]) * (a[i + 1] - a[i + 3]) > 0 &&
			1ll * (a[i + 2] - a[i]) * (a[i + 2] - a[i + 3]) > 0 &&
			1ll * (a[i + 2] - a[i + 1]) * (a[i + 2] - a[i + 3]) > 0)
			++ans;
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