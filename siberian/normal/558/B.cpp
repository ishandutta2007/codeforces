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


void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	map<int, vector<int>> have;
	for (int i = 0; i < n; i++) {
		have[a[i]].push_back(i + 1);
	}
	int ans = 0;
	int l = 0, r = 0;
	for (auto i : have) {
		int cnt = i.second.size();
		if (cnt < ans) continue;
		int l1 = *min_element(all(i.second));
		int r1 = *max_element(all(i.second));
		if (cnt > ans || r1 - l1 < r - l) {
			ans = cnt;
			r = r1;
			l = l1;
		} 
	}
	cout << l << " " << r << endl;
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