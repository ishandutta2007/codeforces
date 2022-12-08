#include <bits/stdc++.h>

using namespace std;

string s[100005];

#define PY cout << "YES\n";return

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> s[i];
	set<string> g;
	for (int i = 0; i < n; ++i) {
		if (s[i].length() == 1 || s[i].length() == 2 && s[i][0] == s[i][1] ||
			s[i].length() == 3 && s[i][0] == s[i][2]) {
			PY;
		}
		if (s[i].length() == 2) {
			string tmp = s[i];
			reverse(tmp.begin(), tmp.end());
			if (g.find(tmp) != g.end()) {
				PY;
			}
			for (int j = 0; j < 26; ++j) {
				if (g.find(tmp + char('a' + j)) != g.end()) {
					PY;
				}
			}
		}
		if (s[i].length() == 3) {
			string tmp = s[i];
			reverse(tmp.begin(), tmp.end());
			if (g.find(tmp) != g.end()) {
				PY;
			}
			tmp.pop_back();
			if (g.find(tmp) != g.end()) {
				PY;
			}
		}
		g.insert(s[i]);
	}
	cout << "NO\n";
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