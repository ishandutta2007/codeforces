#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

int f(int x) {
	if (x == 0) return 0;
	if (x & 1) return f((x - 1) / 2) + 1;
	return f(x / 2);
}

void solve() {
	int n;
	cin >> n;
	map<int, int> a;
	for (int i = 0; i < n; i++) {
		int x = 0;
		cin >> x;
		a[f(x)]++;
	}
	//for (auto i : a)
	//	cout << i.first << " " << i.second << endl;
	int ans = 0;
	for (auto i : a) {
		ans += i.second * (i.second - 1) / 2;
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