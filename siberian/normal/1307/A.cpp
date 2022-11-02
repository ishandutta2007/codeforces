#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> a;
	a.resize(n);
	for (auto &i : a)
		cin >> i;
	for (int i = 0; i < d; i++) {
		for (int j = 1; j < n; j++) {
			if (a[j] > 0) {
				a[j - 1]++;
				a[j]--;
				break;
			}
		}
	}
	cout << a[0] << "\n";
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