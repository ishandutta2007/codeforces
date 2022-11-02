#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int get(int len) {
	return len * 4 - 4;
}

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 1; i <= n / 2; i++) {
		ans += i * get(2 * i + 1);
	}
	cout << ans << "\n";
	//exit(0);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}