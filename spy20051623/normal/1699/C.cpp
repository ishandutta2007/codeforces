#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), p(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		p[a[i]] = i;
	}
	int l = p[0], r = p[0];
	long long ans = 1;
	for (int i = 1; i < n; ++i) {
		if (p[i] < l) l = p[i];
		else if (p[i] > r) r = p[i];
		else ans = ans * (r - l - i + 1) % mod;
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}