#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int N = 507;
const int MOD = 998244353;
const int INF = MOD;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) {
		x -= MOD;
	}
}

int dp[N][N];

int main() {
	//freopen("F.in", "r", stdin);
	//freopen("F.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i][i + 1] = 1;
		dp[i][i] = 1;
	}
	dp[n][n] = 1;
	for (int len = 2; len <= n; len++) {
		for (int l = 0; l < n; l++) {
			int r = l + len;
			if (r > n) break;
			int mn = INF, pos = -1;
			for (int i = l; i < r; i++) {
				if (a[i] < mn) {
					mn = a[i];
					pos = i; 
				}
			}
			int reta = 0, retb = 0;
			for (int i = l; i <= pos; i++) {
				add(reta, dp[l][i] * (ll) dp[i][pos] % MOD);
			}
			for (int i = pos + 1; i <= r; i++) {
				add(retb, dp[pos + 1][i] * (ll) dp[i][r] % MOD);
			}
			dp[l][r] = reta * (ll) retb % MOD;
			//cout << l << " " << r << " " << dp[l][r] << "\n";
		}
	}
	cout << dp[0][n] << "\n";
}