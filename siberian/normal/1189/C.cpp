#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()
template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

#define int ll

const int MAXN = 1e5 + 10, MAXLOG = 17;
int n;
int a[MAXN];
int dp[MAXN][MAXLOG], num[MAXN][MAXLOG];

void build() {
	for (int i = 0; i < n; i++)
		dp[i][0] = 0, num[i][0] = a[i];
	for (int l = 1; l < MAXLOG; l++) {
		for (int i = 0; i + (1 << l) <= n; i++) {
			int x = num[i][l - 1] + num[i + (1 << (l - 1))][l - 1];
			dp[i][l] = dp[i][l - 1] + dp[i + (1 << (l - 1))][l - 1];
			if (x >= 10) dp[i][l]++;
			num[i][l] = x % 10;
		}
	}
}

int Log(int x) {
	int ans = 0;
	while (x) {
		ans++;
		x /= 2;
	}
	return ans;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	build();
	/*cout << "dp = " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= Log(n); j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << "num = " << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= Log(n); j++) {
			cout << num[i][j] << " ";
		}
		cout << endl;
	}*/
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		cout << dp[l][Log(r - l)] << "\n";
	}
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