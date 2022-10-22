#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
 
#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 200 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// pref, cost, numb c1
ll dp[MAXN][MAXN][MAXN] = {0};

ll upd(ll& a, ll b) {
	a = max(a, b);
	return a;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	char c1, c2;
	cin >> c1 >> c2;
	if (c1 == c2) {
		ll p = min(n, count(all(s), c1) + k);
		cout << p * (p - 1) / 2 << endl;
		return 0;

	}
	
	s = 'N' + s;
	for (int k = 0; k < MAXN; k++)
		for (int i = 0; i < MAXN; i++) 
			for (int j = 0; j < MAXN; j++) 
				dp[k][i][j] = -1 * INF;

	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < MAXN; k++) {
				if (s[i] == c1) {
					if (k > 0) upd(dp[i][j][k], dp[i - 1][j][k - 1]);
					if (j > 0) upd(dp[i][j][k], dp[i - 1][j - 1][k] + k);
				} else if (s[i] == c2) {
					upd(dp[i][j][k], dp[i - 1][j][k] + k);
					if (j > 0 && k > 0) upd(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
				} else {
					upd(dp[i][j][k], dp[i - 1][j][k]);
					if (j > 0 && k > 0) upd(dp[i][j][k], dp[i - 1][j - 1][k - 1]);
					if (j > 0) upd(dp[i][j][k], dp[i - 1][j - 1][k] + k);
				}
			}
		}
	}

	ll ans = 0;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j <= k; j++) {
			for (int k = 0; k < MAXN; k++) {
				ans = max(ans, dp[i][j][k]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}