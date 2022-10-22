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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][4] = {0};

void mkey(ll& a) {
	while (a < 0) a += MOD;
	while (a >= MOD) a -= MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	ll n;
	cin >> n;
	ll q = 0;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		dp[i][1] = dp[i - 1][1];
		dp[i][2] = dp[i - 1][2];
		dp[i][3] = dp[i - 1][3];
		if (c == 'a') mkey(dp[i][1] += poww(3ll, q, MOD)); 
		else if (c == 'b') mkey(dp[i][2] += dp[i][1]);
		else if (c == 'c') mkey(dp[i][3] += dp[i][2]);
		else {
			mkey(dp[i][3] += dp[i][2] + 2 * dp[i - 1][3]);
			mkey(dp[i][2] += dp[i][1] + 2 * dp[i - 1][2]);
			mkey(dp[i][1] += poww(3ll, q, MOD) + 2 * dp[i - 1][1]);
			q++;
		}
	}
	
	cout << dp[n][3] << endl;
	return 0;
}