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

void Inf() {
	cout << "Infinity" << endl;
	exit(0);
}

void inf() {
	cout << "-Infinity" << endl;
	exit(0);
}

void zero() {
	cout << "0/1" << endl;
	exit(0);
}

void solve() {
	int n, m;
	cin >> n >> m;
	n++;
	m++;
	vector<int> a(n), b(m);
	for (auto &i : a) cin >> i;
	for (auto &i : b) cin >> i;
	int x = a[0], y = b[0];
	if (n > m) {
		if (x * y > 0) {
			Inf();
		} else {
			inf();
		}
	} else if (n < m) {
		zero();
	} else {
		int g = __gcd(abs(x), abs(y));
		if (y < 0) {x *= -1, y *= -1;}
		cout << x / g << "/" << y / g << endl;
	}
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