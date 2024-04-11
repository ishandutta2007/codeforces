#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(a) (a).begin(),(a).end()

template<typename T1, typename T2> inline void chkmin(T1 & x, const T2 & y) {if (y < x) x = y;}
template<typename T1, typename T2> inline void chkmax(T1 & x, const T2 & y) {if (x < y) x = y;}

const int MAXN = 4010;
int n;
int p[MAXN];
int cnt;
int a[MAXN];
bool dp[MAXN];

void solve() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		cin >> p[i];
	}
	cnt = 0;
	int r = 2 * n - 1;
	while (r >= 0) {
		int pos = max_element(p, p + r + 1) - p;
		a[cnt++] = r - pos + 1;
		r = pos - 1;
	}
	/*cout << "a = " << endl;
	for (int i = 0; i < cnt; i++) {
		cout << a[i] << " ";
	}
	cout << endl;*/
	for (int i = 1; i <= n; i++) {
		dp[i] = false;
	}
	dp[0] = true;
	for (int i = 0; i < cnt; i++) {
		for (int w = n; w >= a[i]; w--) {
			dp[w] = dp[w] | dp[w - a[i]];
		}
	}
	if (dp[n]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

signed main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(20), cout.setf(ios::fixed);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}