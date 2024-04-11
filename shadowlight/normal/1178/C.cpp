#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll MOD = 998244353;

ll power(ll a, ll k) {
	if (!k) {
		return 1;
	}
	ll b = power(a, k / 2);
	b = b * b % MOD;
	if (k % 2) {
		return a * b % MOD;
	} else {
		return b;
	}
}

int main() {
	//freopen("C.in", "r", stdin);
	//freopen("C.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	ll w, h;
	cin >> w >> h;
	vector <vector <ll> > dp(w + 1, vector <ll> (h + 1, 0));
	dp[1][1] = 4;
	for (ll i = 1; i <= w; i++) {
		dp[i][1] = 4 * power(2, i - 1) % MOD;
	}
	for (ll i = 1; i <= h; i++) {
		dp[1][i] = 4 * power(2, i - 1) % MOD;
	}
	for (ll i = 2; i <= w; i++) {
		for (ll j = 2; j <= h; j++) {
			dp[i][j] = 4 * dp[i - 1][j - 1] % MOD;
		}
	}
	cout << dp[w][h] << "\n";
}