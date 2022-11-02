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
	vector<pair<string, string>> a(n);
	for (auto &i : a)
		cin >> i.first >> i.second;
	vector<int> p(n);
	for (auto &i : p) cin >> i, i--;

	string last = "";

	for (auto j : p) {
		auto i = a[j];
		string mn = min(i.first, i.second);
		string mx = max(i.first, i.second);
		if (last < mn) {
			last = mn;
			continue;
		}
		if (last < mx) {
			last = mx;
			continue;
		}
		cout << "NO";
		return;
	}
	cout << "YES";
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