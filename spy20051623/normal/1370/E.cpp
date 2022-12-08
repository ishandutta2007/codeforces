#include <bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	string r;
	int c1 = 0, c2 = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') ++c1;
		if (t[i] == '0') ++c2;
		if (s[i] != t[i]) r += s[i];
	}
	if (c1 != c2) {
		cout << "-1\n";
		return 0;
	}
	int cur = 0, mx = 0, mn = 0;
	for (char i: r) {
		if (i == '0') ++cur;
		else --cur;
		mx = max(mx, cur);
		mn = min(mn, cur);
	}
	cout << mx - mn << '\n';
	return 0;
}