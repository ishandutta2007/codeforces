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
 
const ll MAXN = 15 + 3;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN][MAXN][3] = {0};
ll fact[MAXN], W[MAXN][MAXN][MAXN];

ll mkey(ll& x) {
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	fact[0] = 1;
       	for (int i = 1; i < MAXN; i++) fact[i] = fact[i - 1] * i % MOD;	
	dp[1][0][0][0] = dp[0][1][0][1] = dp[0][0][1][2] = 1;
	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			for (int k = 0; k < MAXN; k++) {
				if (i + j + k < 2) continue;
				if (i > 0) mkey(dp[i][j][k][0] = dp[i - 1][j][k][1] + dp[i - 1][j][k][2]);
				if (j > 0) mkey(dp[i][j][k][1] = dp[i][j - 1][k][0] + dp[i][j - 1][k][2]);
				if (k > 0) mkey(dp[i][j][k][2] = dp[i][j][k - 1][0] + dp[i][j][k - 1][1]);
			}
		}
	}

	for (int i = 0; i < MAXN; i++)
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < MAXN; k++)
				W[i][j][k] = fact[i] * fact[j] % MOD * fact[k] % MOD * (dp[i][j][k][0] + dp[i][j][k][1] + dp[i][j][k][2]) % MOD;
	
	ll n, t;
	cin >> n >> t;
	vector<pll> v;
	for (int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}

	ll mx = poww(2ll, n, MOD), ans = 0;
	
	for (int st = 0; st < mx; st++) {
		ll j = 0, sum = 0, g0 = 0, g1 = 0, g2 = 0;
		ll tmp = st;
		while (tmp > 0) {
			if (tmp & 1) {
				pll e = v[j];
				sum += e.X;;
				if (e.Y == 1) g0++;	
				if (e.Y == 2) g1++;	
				if (e.Y == 3) g2++;	
			}

			tmp /= 2;
			j++;
		} 

		if (sum == t) mkey(ans += W[g0][g1][g2]);
	}

	cout << ans << endl;
	return 0;
}