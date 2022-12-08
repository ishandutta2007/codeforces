#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (s[0] != '9') {
		for (int i = 0; i < n; ++i) {
			cout << '9' - s[i];
		}
		cout << '\n';
	} else {
		int c = 0;
		string ans;
		for (int i = n - 1; i >= 0; --i) {
			if (1 - c >= s[i] - '0') ans += char(1 - c - (s[i] - '0') + '0'), c = 0;
			else ans += char(11 - c - (s[i] - '0') + '0'), c = 1;
		}
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}
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