#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6  + 10;

void solve() {
	int n, v;
	cin >> n >> v;
	map<int, int> a;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		a[x] += y;
	}
	int ans = 0;
	for (int i = 1; i <= 100000; i++) {
		int add = min(a[i - 1], v);
		ans += add;
		int fadd = min(a[i], v - add);
		a[i] -= fadd;
		ans += fadd;
	} 
	cout << ans;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	//cin >> t;
	while (t--) solve();
	return 0;
}