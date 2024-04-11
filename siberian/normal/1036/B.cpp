#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k < max(n, m)) {
		cout << -1 << "\n";
		return;
	}

	int ans = k;

	if (n % 2 != m % 2) {
		ans -= 1;
	}
	else if (max(n, m) % 2 != k % 2) {
		ans -= 2;
	}
	cout << ans << "\n";
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