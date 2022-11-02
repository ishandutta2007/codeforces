#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

void solve() {
	int n, m, x, y;
	cin >> n >> m >> x >> y;
	int cnt_all = 0, cnt_pair = 0;
	for (int i = 0; i < n; i++) {
		int len = 0;
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			if (a == '*') {
				cnt_pair += len / 2;
				cnt_all += len;
				len = 0;
			} else {
				len++;
			}
		}
		cnt_pair += len / 2;
		cnt_all += len;		
	}
	int ans = x * cnt_all;
	chkmin(ans, x * (cnt_all - cnt_pair * 2) + y * cnt_pair);
	cout << ans << "\n";
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}