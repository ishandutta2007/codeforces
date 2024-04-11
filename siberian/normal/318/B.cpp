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
	string s;
	cin >> s;
	int ans = 0;
	int cnt = 0;
	for (int i = 0; i + 4 < s.size(); i++) {
		string now = "";
		now += s[i];
		now += s[i + 1];
		now += s[i + 2];
		now += s[i + 3];
		now += s[i + 4];
		if (now == "heavy") cnt++;
		if (now == "metal") ans += cnt;
	}
	cout << ans;
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