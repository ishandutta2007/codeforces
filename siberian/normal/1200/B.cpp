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
	vector<int> a(n);
	for (auto &i : a)
		cin >> i;
	for (int i = 0; i < n - 1; i++) {
		int need = max(a[i + 1] - k, 0LL);
		if (a[i] >= need) {
			int d = a[i] - need;
			m += d;
		}
		else {
			int d = need - a[i];
			if (d > m) {
				cout << "NO\n";
				return;
			} 
			m -= d;
		}
	}
	cout << "YES" << "\n";
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