#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n;
	cin >> n;
	int XL = -1e5, XR = 1e5, YD = -1e5, YU = 1e5;
	for (int i = 0; i < n; i++) {
		int x, y, t1, t2, t3, t4;
		cin >> x >> y;
		cin >> t1;
		if (t1 == 0)
			chkmax(XL, x);
		cin >> t2;
		if (t2 == 0)
			chkmin(YU, y);
		cin >> t3;
		if (t3 == 0)
			chkmin(XR, x);
		cin >> t4;
		if (t4 == 0)
			chkmax(YD, y);		
	}
	if (XL <= XR && YD <= YU) {
		cout << 1 << " " << XL << " " << YD << "\n";
	}
	else {
		cout << "0\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}