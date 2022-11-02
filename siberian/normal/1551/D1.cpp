#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

#define all(a) (a).begin(), (a).end()

template<typename T1, typename T2>
inline void chkmin(T1& x, const T2& y) {
	if (y < x) {
		x = y;
	}
}

template<typename T1, typename T2>
inline void chkmax(T1& x, const T2& y) {
	if (x < y) {
		x = y;
	}
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	bool SWAP = false;
	if (m % 2 == 1) {
		SWAP = true;
		swap(n, m);
		k = n * m / 2 - k;
	}
	if (n % 2 == 0) {
		if (k % 2 == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	} else {
		k -= m / 2;
		if (k < 0) {
			cout << "NO\n";
		} else {
			if (k % 2 == 0) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}