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
	int cnt0 = 0, cnt1 = 0;
	for (auto i : s) {
		cnt0 += i == '0';
		cnt1 += i == '1';
	}
	int ans = min(cnt0, cnt1) %  2;
	if (ans) cout << "DA\n";
	else cout << "NET\n";
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