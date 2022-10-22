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
 
const ll MAXN = 500 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

bool dp[MAXN][MAXN] = {false};
pll A[MAXN];
ll n, k, s = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> A[i].X >> A[i].Y, s += A[i].X, s += A[i].Y; 	
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (dp[i - 1][(j - (A[i].X % k) + k) % k]) dp[i][j] = true;
			for (int p = 0; p < min(k, A[i].X + 1); p++) {	
				ll prv = (j - p + k) % k;
				if (dp[i - 1][prv] && (A[i].X - p) % k + A[i].Y >= k) dp[i][j] = true; 
			}
		}
	}
		
	ll ans = 0;
	for (int j = 0; j < k; j++) if (dp[n][j]) ans = max(ans, (s - j) / k);
	cout << ans << endl;
	return 0;
}