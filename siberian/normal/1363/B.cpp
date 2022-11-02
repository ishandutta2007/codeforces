#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	string s;
	cin >> s;
	int ans = (int)s.size();
	int cnt0 = 0;
	int cnt1 = 0;
	for (auto i : s) {
		cnt0 += i == '0';
		cnt1 += i == '1';
	}
	chkmin(ans, cnt0);
	chkmin(ans, cnt1);
	int cnt0L = 0, cnt1L = 0;
	for (auto i : s) {
		cnt0 -= i == '0';
		cnt1 -= i == '1';
		cnt0L += i == '0';
		cnt1L += i == '1';
		chkmin(ans, cnt0 + cnt1L);
		chkmin(ans, cnt1 + cnt0L);
	}
	cout << ans << "\n";
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