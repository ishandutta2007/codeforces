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
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	for (int i = 1; i < n; ++i) {
		b[i] += b[i - 1];
	}
	for (int i = n - 2; i >= 0; --i) {
		a[i] += a[i + 1];
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i) {
		int fans = 0;
		if (i - 1 >= 0) chkmax(fans, b[i - 1]);
		if (i + 1 < n) chkmax(fans, a[i + 1]);
		chkmin(ans, fans); 
	}
	cout << ans << '\n';
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