#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<bool> used1(n), used2(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			if (x) {
				used1[i] = true;
				used2[j] = true;
			}
		}
	}
	int cnt1 = 0, cnt2 = 0;
	for (auto i : used1) {
		cnt1 += i == 0;
	}
	for (auto i : used2) {
		cnt2 += i == 0;
	}
	int ans = min(cnt1, cnt2);
	if (ans % 2 == 0) {
		cout << "Vivek\n";
	} else {
		cout << "Ashish\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}