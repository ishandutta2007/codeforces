#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6 + 10;

void solve() {
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	map<char, int> cnt;
	for (auto i : s) cnt[i]++;
	for (auto i : t) cnt[i]++;
	for (auto i : cnt) {
		if (i.second % 2) {
			cout << "No\n";
			return;
		}
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {
			continue;
		}
		bool fans = false;
		for (int j = i + 1; j < n; j++) {
			if (s[i] == s[j]) {
				ans.push_back({j, i});
				swap(s[j], t[i]);
				fans = true;
				break;
			}
		}
		
		if (fans) continue;
		for (int j = i + 1; j < n; j++) {
			if (s[i] == t[j]) {
				ans.push_back({n - 1, j});
				swap(s[n - 1], t[j]);
				ans.push_back({n - 1, i});
				swap(s[n - 1], t[i]);
				break;
			}
		}
	}
	cout << "Yes\n";
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first + 1 << " " << i.second + 1 << endl;
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) solve();
	return 0;
}


/*
1
1
abc
bca
*/