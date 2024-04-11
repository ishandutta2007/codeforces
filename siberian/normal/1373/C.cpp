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
	ll ans = s.size();
	int bal = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == '+') bal++;
		else bal--;
		if (bal < 0) {
			ans += (ll)(i + 1) * abs(bal);
			bal = 0;
		}
	}
	cout << ans << endl;
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