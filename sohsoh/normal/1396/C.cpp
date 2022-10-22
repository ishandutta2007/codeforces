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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][2], A[MAXN];

ll upd(ll& x, ll y) {
	x = min(x, y);
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n, r1, r2, r3, d;
	cin >> n >> r1 >> r2 >> r3 >> d;
	for (int i = 1; i <= n; i++) cin >> A[i], dp[i][0] = dp[i][1] = INF;
	dp[1][0] = r1 * A[1] + r3;
	dp[1][1] = min(r2, r1 * (A[1] + 1));
	
	for (int i = 1; i < n; i++) {
		upd(dp[i + 1][0], dp[i][0] + A[i + 1] * r1 + r3 + d);
		upd(dp[i + 1][1], dp[i][0] + d + min(r2, r1 * A[i + 1] + r1));
		upd(dp[i + 1][0], dp[i][1] + 3 * d + r1 * A[i + 1] + r3 + r1);
		upd(dp[i + 1][0], dp[i][1] + 3 * d + r1 * A[i + 1] + 3 * r1);
		upd(dp[i + 1][0], dp[i][1] + 3 * d + r2 + 2 * r1);
		upd(dp[i + 1][1], dp[i][1] + 3 * d + r1 + r2);
		upd(dp[i + 1][1], dp[i][1] + 3 * d + 2 * r1 + r1 * A[i + 1]);
	}	
	cout << min(dp[n][0], dp[n - 1][1] + 2 * d + A[n] * r1 + r3 + r1) << endl;
	return 0;
}