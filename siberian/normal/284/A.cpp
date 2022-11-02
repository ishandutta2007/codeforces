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

int mod;

int mul(int a, int b) {
	return (ll) a * b % mod;
}

int sub(int a, int b) {
	return (a - b + mod * 10) % mod;
}

bool check(int x) {
	int now = 1;
	for (int i = 0; i < mod - 2; i++) {
		now = mul(now, x);
	//	cout << now << endl;
		if (sub(now, 1) == 0) return false;
	}
	now = mul(now, x);
	return sub(now, 1) == 0;
}

void solve() {
	cin >> mod;
	//check(2);
	//areturn;
	int ans = 0;
	for (int i = 1; i < mod; i++)
		ans += check(i);
	cout << ans << endl;
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