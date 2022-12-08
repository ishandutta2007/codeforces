#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 1; i < n - 2; ++i) {
		string ss;
		cin >> ss;
		if (s.back() == ss[0]) s += ss[1];
		else s += ss;
	}
	if (s.length() != n) s += 'a';
	cout << s << '\n';
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