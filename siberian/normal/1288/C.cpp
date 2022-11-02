#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

const int MOD = 1e9 + 7;

int add(int a, int b) {
	return (ll) (a + b) % MOD;
}

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

int n, m;

void read() {
	cin >> n >> m;
}

const int MAXN = 1e3 + 10, MAXM = 20;

int dp[MAXM][MAXN][2];

int ans = 0;

void run() {
	dp[0][0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j][0] = add(dp[i][j][0], dp[i - 1][k][0]);
			}
		}
	}

	dp[0][n + 1][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = n + 1; k >= j; k--) {
				dp[i][j][1] = add(dp[i][j][1], dp[i - 1][k][1]);
			}
		}
	}

	ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = add(ans, mul(dp[m][i][0], dp[m][j][1]));
		}
	}
}

void write() {
	cout << ans << endl;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	run();
	write();
	return 0;
}