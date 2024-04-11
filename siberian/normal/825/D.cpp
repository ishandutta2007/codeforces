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
	map<char, vector<int>> s;
	string t;
	string a;
	cin >> a >> t;
	for (int i = 0; i < a.size(); i++) {
		s[a[i]].push_back(i);
	}
	vector<pair<int, char>> ans;
	int n = a.size();
	int m = t.size();
	for (int i = 0; i < n; i++) {
		int pos = i % m;
		if (s[t[pos]].size() > 0) {
			ans.push_back({s[t[pos]].back(), t[pos]});
			s[t[pos]].pop_back();
			continue;
		}
		if (s['?'].size() > 0) {
			ans.push_back({s['?'].back(), t[pos]});
			s['?'].pop_back();
			continue;
		}
		for (int j = 0; j < 26; j++) {
			if (s[j + 'a'].size() > 0) {
				ans.push_back({s[j + 'a'].back(), j + 'a'});
				s[j + 'a'].pop_back();
				break;
			}
		}
	}
	sort(all(ans));
	for (auto i : ans) cout << i.second;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}


/*
1
1
abc
bca
*/