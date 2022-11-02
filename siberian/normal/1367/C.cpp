#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	bool ok = true;
	for (auto i : s) {
		ok &= i == '0';
	}
	if (ok) {
		cout << 1 + (n - 1) / (k + 1) << endl;
		return;
	}
	int pref = 0;
	int suff = 0;
	while (s.back() == '0') s.pop_back(), suff++;
	reverse(all(s));
	while (s.back() == '0') s.pop_back(), pref++;
	int ans = 0;
	ans += pref / (k + 1);
	ans += suff / (k + 1);
	while (!s.empty()) {
		while (!s.empty() && s.back() == '1') s.pop_back();
		int now = 0;
		while (!s.empty() && s.back() == '0') s.pop_back(), now++;
		now -= 2 * k;
		if (now <= 0) continue;
		ans += 1 + (now - 1) / (k + 1);
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