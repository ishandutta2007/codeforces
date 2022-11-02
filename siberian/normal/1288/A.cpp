#include <bits/stdc++.h>
 
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()
 
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}
 
bool check(int d, int x, int n) {
	//cout << d << " " << x << " " << n << endl;
	return (d + x) / (x + 1) + x <= n;
}
 
void solve() {
	ll n, d;
	cin >> n >> d;
	if (n >= d) {
		cout << "YES\n";
		return;
	}
	ll x = sqrt(d);
	for (int i = max(0LL, x - 10); i <= x + 10; i++) {
		if (check(d, i, n)) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
 
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}