#include <bits/stdc++.h>

using namespace std;

int a[100005];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int mx = 0;
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += a[i];
		mx = max(mx, a[i]);
	}
	if (mx == 0) cout << "0\n";
	else if (sum >= mx + mx) cout << "1\n";
	else cout << mx + mx - sum << '\n';
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