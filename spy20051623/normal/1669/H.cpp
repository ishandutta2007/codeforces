#include <bits/stdc++.h>

using namespace std;

long long a[200005], s[200005];

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> c(50);
	for (int i = 0; i < n; ++i) {
		int p;
		cin >> p;
		for (int j = 0; j <= 30; ++j) {
			if (p >> j & 1) ++c[j];
		}
	}
	int ans = 0;
	for (int i = 30; i >= 0; --i) {
		if (n - c[i] <= k) {
			ans |= 1 << i;
			k -= n - c[i];
		}
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