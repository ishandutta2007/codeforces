#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

bool check(int k, int n, int a, int b, int cnta) {
	return k - a * cnta - (n - cnta) * b > 0;
}

void solve() {
	int k, n, a, b;
	cin >> k >> n >> a >> b;
	int l = -1, r = n + 1;
	while (l < r - 1){
		int mid = (l + r) / 2;
		if (check(k, n, a, b, mid))
			l = mid;
		else
			r = mid;
	} 
	cout << l << "\n";
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