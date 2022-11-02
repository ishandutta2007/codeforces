#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, m;
	cin >> n >> m;
	if ((n * m) % 2 == 0) {
		bool flag = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!flag) {
					if (n * m % 2 == 0) {
						cout << 'B';
					} else {
						cout << 'W';
					}
					flag = true;
					continue;
				}
				if ((i + j) % 2 == 0) {
					cout << 'W';
				} else {
					cout << 'B';
				}
			}
			cout << "\n";
		}
	} else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((i + j) % 2 == 0) {
					cout << 'B';
				} else {
					cout << 'W';
				}
			}
			cout << "\n";
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}