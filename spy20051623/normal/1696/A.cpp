#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n, z;
	cin >> n >> z;
	vector<int> a(n);
	int mx = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mx = max(mx, a[i] | z);
	}
	cout << mx << "\n";
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