#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

bool check(int s, int i, int e, int x) {
	return s + x > i + e - x;
}

void solve() {
	int s, i, e;
	cin >> s >> i >> e;
	if (s + e <= i) {
		cout << 0 << "\n";
		return;
	}
	int l = -1, r = e;
	while (l < r - 1) {
		int mid = (l + r) / 2;
		if (check(s, i, e, mid))
			r = mid;
		else
			l = mid;
	}
	cout << e - r + 1 << "\n";
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