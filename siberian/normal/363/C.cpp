#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

string s;

void solve() {
	cin >> s;
	vector<pair<char, int>> have;
	for (auto i : s) {
		if (have.empty() || have.back().first != i) {
			have.push_back({i, 1});
		}
		else {
			have[have.size() - 1].second++;
		}
	}
	for (auto &i : have) {
		chkmin(i.second, 2);
	}
	for (int i = 1; i < have.size(); i++) {
		if (have[i - 1].second == 1) continue;
		if (have[i].second == 1) continue;
		chkmin(have[i].second, 1);
	}
	for (auto i : have) {
		while(i.second--)
			cout << i.first;
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