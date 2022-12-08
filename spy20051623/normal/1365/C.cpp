#include <bits/stdc++.h>

using namespace std;

int a[200005], b[200005], c[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a[x] = i;
	}
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		b[x] = i;
	}
	for (int i = 1; i <= n; ++i) {
		if (a[i] >= b[i]) ++c[a[i] - b[i]];
		else ++c[n + a[i] - b[i]];
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, c[i]);
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
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}