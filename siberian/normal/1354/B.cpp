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
	int n = s.size();
	int last[3];
	last[0] = last[1] = last[2] = -1;
	int ans = n + 1;
	for (int i = 0; i < n; i++) {
		last[s[i] - '1'] = i;
		if (last[0] < 0 || last[1] < 0 || last[2] < 0) continue;
		chkmin(ans, i - min(last[0], min(last[1], last[2])) + 1);
	}
	if (ans == n + 1) ans = 0;
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