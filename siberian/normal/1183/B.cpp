#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a;
	int min_x = 1e18;
	int max_x = -1e18;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		chkmax(max_x, x);
		chkmin(min_x, x);
	}
	if (min_x + k < max_x - k) {
		cout << -1 << endl;
		return;
	}
	cout << min_x + k << endl;
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