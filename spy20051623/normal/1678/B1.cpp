#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		int cnt = 1;
		while (i < n - 1 && s[i + 1] == s[i]) {
			++i;
			++cnt;
		}
		sum += cnt;
		if (sum & 1) ++ans;
	}
	cout << ans << "\n";
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