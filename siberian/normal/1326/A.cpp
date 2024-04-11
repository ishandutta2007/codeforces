#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve () {
	int n;
	cin >> n;
	if (n == 1) {
		cout << -1 << "\n";
		return;
	}
	if (n % 3 == 1) {
		for (int i = 0; i < n - 2; i++)
			cout << 2;
		cout << 33;
		cout << "\n";
	}
	else {
		for (int i = 0; i < n - 1; i++)
			cout << 2;
		cout << 3;
		cout << "\n";
	}
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