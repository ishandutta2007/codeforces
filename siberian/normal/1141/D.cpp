#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6  + 10;

void solve() {
	int n;
	cin >> n;
	map<char, vector<int>> l, r;
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		l[x].push_back(i + 1);
	}	
	for (int i = 0; i < n; i++) {
		char x;
		cin >> x;
		r[x].push_back(i + 1);
	}
	vector<pair<int, int>> ans;
	for (int i = 0; i < 26; i++) {
		while (!l[i + 'a'].empty() && !r[i + 'a'].empty()) {
			ans.push_back({l[i + 'a'].back(), r[i + 'a'].back()});
			l[i + 'a'].pop_back();
			r[i + 'a'].pop_back();
		}
	}
	for (int i = 0; i < 26; i++) {
		while (!l[i + 'a'].empty() && !r['?'].empty()) {
			ans.push_back({l[i + 'a'].back(), r['?'].back()});
			l[i + 'a'].pop_back();
			r['?'].pop_back();
		}
	}
	for (int i = 0; i < 26; i++) {
		while (!r[i + 'a'].empty() && !l['?'].empty()) {
			ans.push_back({l['?'].back(), r[i + 'a'].back()});
			r[i + 'a'].pop_back();
			l['?'].pop_back();
		}
	}
	while (!r['?'].empty() && !l['?'].empty()) {
		ans.push_back({l['?'].back(), r['?'].back()});
		l['?'].pop_back();
		r['?'].pop_back();
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first << " " << i.second << "\n"; 
 	}
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