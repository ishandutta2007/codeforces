#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ans += b - a > 1;
	}
	cout << ans;
	return 0;
	int t;
	//cin >> t;	
	t = 1;
	while (t--)
		solve();
	return 0;
}