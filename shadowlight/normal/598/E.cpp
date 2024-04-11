#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll Q = 31;
const ll cnt = 51;
const ll INF = 1e18 + 7;

ll dp[Q][Q][cnt];

int main() {
	//freopen("E.in", "r", stdin);
	//freopen("E.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	for (ll i = 0; i < Q; i++) {
		for (ll j = 0; j < Q; j++) {
			for (ll k = 0; k < cnt; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	for (ll i = 1; i < Q; i++) {
		for (ll j = 1; j < Q; j++) {
			if (i * j < cnt) {
				dp[i][j][i * j] = 0;
			}
			dp[i][j][0] = 0;
			for (ll k = 0; k < cnt; k++) {
				for (ll a = 0; a <= k; a++) {
					for (ll d = 1; d < i; d++) {
						dp[i][j][k] = min(dp[i][j][k], dp[d][j][a] + dp[i - d][j][k - a] + j * j);
					}
					for (ll d = 1; d < j; d++) {
						dp[i][j][k] = min(dp[i][j][k], dp[i][d][a] + dp[i][j - d][k - a] + i * i);
					}
				}
			}
		}
	}
	for (ll i = 0; i < t; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		cout << dp[a][b][c] << "\n";
	}
}