#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		if (x == 1) {
			cout << "FastestFinger" << endl;
		} else if (x == 2) {
			cout << "Ashishgup" << endl;
		} else if (x % 2 == 1) {
			cout << "Ashishgup" << endl;
		} else {
			int cnt = 0;
			int have = x % 4;
			for (int i = 2; i * i <= x; i++) {
				while (x % i == 0) {
					cnt += i % 2;
					x /= i;
				}
			}
			if (x > 1) cnt += x % 2;
			if (cnt > 1 || (cnt == 1 && have == 0)) {
				cout << "Ashishgup" << endl;
			} else {
				cout << "FastestFinger" << endl;
			}
		}
	}
	return 0;
}