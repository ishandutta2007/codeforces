#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	int cnt01 = 0, cnt10 = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x %= 2;
		if (i % 2 == x) continue;
		if (i % 2 == 0) cnt01++;
		else cnt10++;
	}
	if (cnt10 != cnt01) {
		cout << -1 << endl;
	} else {
		cout << cnt10 << endl;
	}
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