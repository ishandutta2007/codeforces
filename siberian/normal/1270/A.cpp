#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}



signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		int fans1 = 0;
		for (int i = 0; i < k1; i++) {
			int x;
			cin >> x;
			chkmax(fans1, x);
		}
		int fans2 = 0;
		for (int i = 0; i < k2; i++) {
			int x;
			cin >> x;
			chkmax(fans2, x);
		}
		if (fans1 > fans2) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}