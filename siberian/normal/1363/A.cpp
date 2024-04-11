#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, x;
	cin >> n >> x;
	int cnt0 = 0, cnt1 = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a % 2) cnt1++;
		else cnt0++;
	}
	if (cnt1 == 0) {
		cout << "NO\n";
		return;
	}
	if (x % 2 == 0 && cnt0 == 0) {
		cout << "NO\n";
		return;
	}
	if (x == n && cnt1 % 2 == 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
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