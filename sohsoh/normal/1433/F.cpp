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
 
const ll MAXN = 70 + 10;
const ll INF = 1e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN], A[MAXN][MAXN], val[MAXN][MAXN], n, m, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> A[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAXN; j++) fill(dp[j], dp[j] + MAXN, -INF);
		dp[0][0] = 0;
		fill(val[i], val[i] + MAXN, -INF);
		// tdp (i, j), picking i, % k == j
		for (int x = 1; x <= m; x++)
			for (int j = m; j >= 1; j--) 
				for (int md = 0; md < k; md++) 
					dp[j][md] = max(dp[j][md], dp[j - 1][(md - (A[i][x] % k) + k) % k] + A[i][x]);
		for (int p = 0; p <= m / 2; p++) for (int md = 0; md < k; md++) val[i][md] = max(val[i][md], dp[p][md]);

	}
	
	for (int j = 0; j < MAXN; j++) fill(dp[j], dp[j] + MAXN, -INF);
	dp[0][0] = 0;	
	for (int i = 1; i <= n; i++) {
		for (int md = 0; md < k; md++) {
			for (int md2 = 0; md2 < k; md2++) {
				dp[i][md] = max(dp[i][md], dp[i - 1][(md - md2 + k) % k] + val[i][md2]);
			}
		}
	}

	cout << dp[n][0] << endl;
	return 0;
}