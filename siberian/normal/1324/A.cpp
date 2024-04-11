#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}


void solve() {
	int n;
	cin >> n;
	int a;
	cin >> a;
	a %= 2;
	bool ans = true;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		ans &= a == x % 2;
	}
	if (ans) cout << "YES\n";
	else cout << "NO\n";
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