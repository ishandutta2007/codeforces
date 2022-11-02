#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

void solve() {
	int n, a, b;
	string s;
	cin >> n >> a >> b >> s;
	int cnt = 1;
	for (int i = 1; i < n; ++i) {
		cnt += s[i] != s[i - 1];
	}
	int ans = a * n;
	if (b >= 0) {
		ans += b * n;
	} else {
		while (cnt > 2) {
			ans += b;
			cnt -= 2;
		}
		ans += b * cnt;
	}
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}