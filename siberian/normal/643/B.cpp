#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e6 + 10;

void solve() {
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	if (k < n + 1 || n == 4) {
		cout << -1;
		return;
	}
	set<int> x = {a, b, c, d};
	cout << a << " " << c << " ";
	for (int i = 1; i <= n; i++) {
		if (!x.count(i)) cout << i << " ";
	}
	cout << d << " " << b << endl;
	cout << c << " " << a << " ";
	for (int i = 1; i <= n; i++) {
		if (!x.count(i)) cout << i << " ";
	}
	cout << b << " " << d << endl;
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


/*
1
1
abc
bca
*/