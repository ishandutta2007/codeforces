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
	int n, k;
	cin >> n >> k;
	int ans = n + 1;
	for (int i = 0; i < k; i++) {
		int m;
		cin >> m;
		ans += m - 1;
		vector<int> x(m);
		for (int j = 0; j < m; j++) {
			cin >> x[j];
			if (x[j] == j + 1) {
				ans -= 2;
			}
		}
	}
	cout << ans << endl;
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