#include <bits/stdc++.h>

using namespace std;

int a[200005], b[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i] != i;
	}
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += b[i] * !b[i - 1];
	}
	cout << min(ans, 2) << '\n';
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