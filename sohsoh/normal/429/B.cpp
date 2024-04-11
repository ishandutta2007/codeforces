/*
    Soheil Mohammadkhani
    IDK :)
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;

const ll MAXN = 1000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9


ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

ll dp[4][MAXN][MAXN] = {0}, A[MAXN][MAXN];

int main() {
	ll n, m;
	cin >> n >> m;	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
		}
	} 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp[0][i][j] = A[i][j];
			ll x = 0;
			if (i) x = dp[0][i - 1][j];
			if (j) x = max(x, dp[0][i][j - 1]);
			dp[0][i][j] += x;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			dp[3][i][j] = A[i][j];
			ll x = 0;
			if (i) x = dp[3][i - 1][j];
			if (j < m - 1) x = max(x, dp[3][i][j + 1]);
			dp[3][i][j] += x;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			dp[1][i][j] = A[i][j];
			ll x = 0;
			if (i <= n - 1) x = dp[1][i + 1][j];
			if (j < m - 1) x = max(x, dp[1][i][j + 1]);
			dp[1][i][j] += x;
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < m; j++) {
			dp[2][i][j] = A[i][j];
			ll x = 0;
			if (i <= n - 1) x = dp[2][i + 1][j];
			if (j) x = max(x, dp[2][i][j - 1]);
			dp[2][i][j] += x;
		}
	}

	ll ans = 0;
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < m - 1; j++) {
			ans = max(ans, max(dp[0][i - 1][j] + dp[1][i + 1][j] + dp[2][i][j - 1] + dp[3][i][j + 1], dp[0][i][j - 1] + dp[1][i][j + 1] + dp[2][i + 1][j] + dp[3][i - 1][j]));
		}
	}

	cout << ans << endl;

}