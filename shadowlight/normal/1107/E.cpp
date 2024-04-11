#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 107;
const ll INF = 1e18 + 7;

vector <ll> a, dpa, dpb;
ll n;
string s;

ll dp[N][N][N][2];

void calc() {
	for (ll i = 1; i <= n; i++) {
		for (ll j = 0; j < i; j++) {
			dpa[i] = max(dpa[i], dpa[j] + a[i - j]);
		}
	}
	for (ll i = 0; i < N; i++) {
		for (ll j = 0; j < N; j++) {
			for (ll k = 0; k < N; k++) {
				for (ll t = 0; t < 2; t++) {
					dp[i][j][k][t] = -INF;
					if (k == 0) {
						dp[i][j][k][t] = 0;
					}
				}
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < 2; j++) {
			dp[i][i + 1][0][j] = a[1];
			if (j == s[i] - '0') {
				dp[i][i + 1][1][j] = 0; 
			}
		}
	}
	for (ll len = 2; len <= n; len++) {
		for (ll l = 0; l < n; l++) {
			ll r = l + len;
			if (r > n) break;
			for (ll i = l; i < r; i++) {
				 for (ll cnt = 0; cnt < N - 1; cnt++) {
				 	if (s[i] == '0') {
				 		dp[l][r][cnt + 1][0] = max(dp[l][r][cnt + 1][0], dp[l][i][0][0] + dp[i + 1][r][cnt][0]);
				 	}
				 	if (s[i] == '1') {
				 		dp[l][r][cnt + 1][1] = max(dp[l][r][cnt + 1][1], dp[l][i][0][1] + dp[i + 1][r][cnt][1]);
				 	}
				 }
			}
			for (ll cnt = 0; cnt < N; cnt++) {
				dp[l][r][0][0] = max(dp[l][r][0][0], dp[l][r][cnt][0] + dpa[cnt]);
			}
			for (ll cnt = 0; cnt < N; cnt++) {
				dp[l][r][0][1] = max(dp[l][r][0][1], dp[l][r][cnt][1] + dpa[cnt]);
			}
			dp[l][r][0][0] = max(dp[l][r][0][0], dp[l][r][0][1]);
			dp[l][r][0][1] = max(dp[l][r][0][0], dp[l][r][0][1]);
			// for (int cnt = 0; cnt < N; cnt++) {
			// 	for (int j = 0; j < 2; j++) {
			// 		if (dp[l][r][cnt][j] >= 0) {
			// 			cerr << l << " " << r << " " << cnt << " " << j << " " << dp[l][r][cnt][j] << "\n";
			// 		}
			// 	}
			// }
			//cout << l << " " << r << "\n";
		}
	}
}

void solve() {
	a.clear();
	dpa.clear();
	cin >> n >> s;
	a.resize(n + 1, 0);
	dpa.resize(N, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i + 1];
	}
	calc();
	cout << dp[0][n][0][0] << "\n";
}

const ll TESTS = 1;

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	for (ll i = 0; i < TESTS; i++) {
		solve();
	}
}