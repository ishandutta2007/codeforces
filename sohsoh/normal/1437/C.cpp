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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 400 + 10;
const ll INF = 8e12;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN], A[MAXN], n;

ll solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) dp[i][j] = INF;
	dp[0][0] = 0;
	sort(A + 1, A + n + 1);
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= 2 * n; j++) {
			// i -> dish, j -> time
			if (i > 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + abs(A[i] - j));
			}
	       		dp[i][j] = min(dp[i][j], dp[i][j - 1]);		
		}
	}


	ll ans = INF;
	for (int i = 0; i < MAXN; i++) ans = min(ans, dp[n][i]);
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}