#include <bits/stdc++.h>

using namespace std;

void solve() {
	string a, b, s;
	cin >> a >> s;
	while (!s.empty()) {
		if (a.length() > s.length()) {
			cout << "-1\n";
			return;
		}
		if (a.empty()) a = "0";
		if (a.back() <= s.back()) {
			b = (char) (s.back() - a.back() + '0') + b;
			s.pop_back();
		} else {
			int t = s.back() - '0';
			s.pop_back();
			if (s.empty() || s.back() != '1') {
				cout << "-1\n";
				return;
			}
			b = (char) (10 + t - (a.back() - '0') + '0') + b;
			s.pop_back();
		}
		a.pop_back();
	}
	while (!b.empty() && b.front() == '0') b.erase(b.begin());
	if (b.empty()) b = "0";
	cout << b << '\n';
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