#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

string get(int l, int r, string s) {
	string ans = "";
	for (int i = l; i <= r; i++)
		ans += s[i];
	sort(all(ans));
	return ans;
}

void solve() {
	string s, t;
	cin >> s >> t;
	sort(all(s));
	for (int i = 0; i + s.size() - 1 < t.size(); i++) {
		if (get(i, i + s.size() - 1, t) == s) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}