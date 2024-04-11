#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	string s;
	cin >> s;
	int m;
	cin >> m;
	vector<int> b(m);
	for (auto &i : b) {
		cin >> i;
	}
	vector<bool> used(m, false);
	int lett = 25;
	vector<int> cnt(26);
	for (auto i : s) {
		cnt[i - 'a']++;
	}
	vector<char> ans(m);
	while (true) {
		vector<int> now;
		for (int i = 0; i < m; i++) {
			if (!used[i] && b[i] == 0) {
				now.push_back(i);
				used[i] = true;
			}
		}
		if (now.empty()) break;

		for (int i = 0; i < m; i++) {
			if (used[i]) continue;
			for (auto j : now) {
				b[i] -= abs(i - j);
			}
		}
		while (cnt[lett] < (int)now.size()) {
			lett--;
		}
		assert(lett >= 0);
		for (auto i : now) {
			ans[i] = 'a' + lett;
		}
		lett--;
	}
	for (auto i : ans) {
		cout << i;
	}
	cout << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}