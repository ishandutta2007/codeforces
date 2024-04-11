/*
	8)
*/
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
#define SZ(x)                       ll(x.size())
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e8; // 998244353; // 1e9 + 9;

ll dp[110][110][2] = {0};

void md(ll& a) {
	if (a >= MOD) a -= MOD;
	else if (a < 0) a += MOD;
}

int main() {
	ll n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp[1][0][0] = dp[0][1][1] = dp[0][0][1] = dp[0][0][0] = 1;
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			
			if(i + j <= 1)
				continue;
			if(i)
			{
				md(dp[i][j][0] += dp[i - 1][j][1]);
				md(dp[i][j][0] += dp[i - 1][j][0]);
				if(i >= k1 + 1)
					md(dp[i][j][0] -= dp[i - k1 - 1][j][1]);
			}
 
			if(j)
			{
				md(dp[i][j][1] += dp[i][j - 1][0]);
				md(dp[i][j][1] += dp[i][j - 1][1]);
				if(j >= k2 + 1)
					md(dp[i][j][1] -= dp[i][j - k2 - 1][0]);
			}
		}
	}

	ll ans = 0;
	md(ans = dp[n1][n2][0] + dp[n1][n2][1]);
 
	cout << ans << endl;
}