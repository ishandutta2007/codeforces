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

int get(int a, int x) {
	int ans = 0;
	while (a % x == 0) {
		a /= x;
		ans++;
	}
	return ans;
}

void no() {
	cout << -1;
	exit(0);
}

void solve() {
	int a, b;
	cin >> a >> b;
	int cnt1 = 0, cnt2 = 0;
	cnt1 = get(a, 5);
	cnt2 = get(b, 5);
	int ans = 0;
	if (cnt1 < cnt2) swap(cnt1, cnt2), swap(a, b);
	cnt1 -= cnt2;
	while (cnt1--) {
		a /= 5;
		ans++;
	}
	cnt1 = get(a, 3);
	cnt2 = get(b, 3);
	if (cnt1 < cnt2) swap(cnt1, cnt2), swap(a, b);
	cnt1 -= cnt2;
	while (cnt1--) {
		a /= 3;
		ans++;
	}
	cnt1 = get(a, 2);
	cnt2 = get(b, 2);
	if (cnt1 < cnt2) swap(cnt1, cnt2), swap(a, b);
	cnt1 -= cnt2;
	while (cnt1--) {
		a /= 2;
		ans++;
	}
	//cout << a << " " << b << endl; 
	if (a != b) no();
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