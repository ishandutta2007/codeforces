#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 3510;

int a[MAXN];

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	k = min(k, m - 1);
	int ans = 0;
	for (int i = 0; i <= k; i++) {
		int fans = 1e9 + 10;
		for (int j = 0; j <= m - 1 - k; j++) {
			int l = i + j;
			int r = m - 1 - l;
			r = n - 1 - r;
			chkmin(fans, max(a[l], a[r]));
		}
		chkmax(ans, fans);
	}
	cout << ans << "\n";
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