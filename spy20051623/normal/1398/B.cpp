#include <bits/stdc++.h>

using namespace std;

void solve() {
	string s;
	cin >> s;
	int n = s.length();
	vector<int> v;
	for (int i = 0; i < n;) {
		int x = i - 1;
		for (int j = i; j < n; ++j) {
			if (s[j] == '1') x = j;
			else break;
		}
		if (x >= i) v.push_back(x - i + 1);
		i = x >= i ? x + 1 : i + 1;
	}
	sort(v.begin(), v.end(), greater<int>());
	int ans = 0;
	for (int i = 0; i < v.size(); i += 2) ans += v[i];
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