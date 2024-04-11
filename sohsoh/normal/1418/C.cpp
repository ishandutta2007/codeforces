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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][2], A[MAXN];

ll solve() {
	ll n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	dp[0][0] = INF;
	dp[0][1] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i][1] = dp[i - 1][0];
		if (A[i]) dp[i][0] = dp[i - 1][1] + 1;
		else dp[i][0] = dp[i - 1][1];
		if (i > 1) {
			dp[i][1] = min(dp[i][1], dp[i - 2][0]);
			ll cnt = A[i] + A[i - 1];
			dp[i][0] = min(dp[i][0], dp[i - 2][1] + cnt);
		}
	}

	cout << min(dp[n][0], dp[n][1]) << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll t;
	cin >> t;
	while (t--) solve();
	return 0;
}