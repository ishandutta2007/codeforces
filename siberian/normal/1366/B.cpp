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
	int n, m, x;
	cin >> n >> x >> m;
	int L = x, R = x;
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		if (l > R || r < L) continue;
		chkmax(R, r);
		chkmin(L, l);
	}
	cout << R - L + 1 << "\n";
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