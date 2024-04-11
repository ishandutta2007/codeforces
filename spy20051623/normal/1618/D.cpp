#include <bits/stdc++.h>

using namespace std;

long long a[10000];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	long long ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += a[k + i] / a[i];
	}
	for (int i = k + k; i < n; ++i) {
		ans += a[i];
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}