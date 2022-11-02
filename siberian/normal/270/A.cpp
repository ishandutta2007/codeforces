#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int x;
	cin >> x;
	for (int n = 3; n <= 10000; n++) {
		if (180 * (n - 2) % n == 0 && 180 * (n - 2) / n == x) {
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