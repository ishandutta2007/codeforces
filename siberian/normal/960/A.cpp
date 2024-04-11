#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
#define fadd fadd228
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void no() {
	cout << "NO\n";
	exit(0);
}

void solve() {
	string s;
	cin >> s;
	string a, b, c;
	for (auto i : s) {
		if (i == 'a') {
			if (b.size() || c.size()) no();
			a += i;
		}
		else if (i == 'b') {
			if (c.size()) no();
			b += i;
		}
		else if (i == 'c') {
			c += i;
		}
		else no();
	}
	if (a.size() != c.size() && b.size() != c.size()) no();
	if (a.empty() || b.empty() || c.empty()) no();
	cout << "YES\n";
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