#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		if (!a[i - 1] && a[i]) ++ans;
	}
	if (ans > 2) ans = 2;
	cout << ans << "\n";
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}