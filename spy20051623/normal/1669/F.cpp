#include <bits/stdc++.h>

using namespace std;

long long a[200005], s[200005];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	map<long long, int> k;
	int ans = 0;
	for (int i = n; i >= 0; --i) {
		if (k.find(s[i]) != k.end()) {
			ans = max(ans, k[s[i]] + i);
		}
		k[s[n] - s[i - 1]] = n - i + 1;
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