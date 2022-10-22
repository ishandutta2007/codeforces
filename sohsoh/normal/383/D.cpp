/*
    Soheil Mohammadkhani
    Sos Goge Tabarok :)
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
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define alog(a, n)                  for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
#define fast_io                     ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll cst = 1e4 + 10;
const ll MAXM = 2 * cst + 20;

ll dp[MAXN][MAXM] = {0};

ll mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return 0;
}

int main() {
	fast_io;
	ll n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		ll x;
	       	cin >> x;
       		for (int j = 0; j < MAXM; j++) {
			if (j - x >= 0) mkey(dp[i][j] += dp[i - 1][j - x]);
			if (j + x < MAXM) mkey(dp[i][j] += dp[i - 1][j + x]);
		}

		mkey(dp[i][cst + x] += 1);
		mkey(dp[i][cst - x] += 1);
		mkey(ans += dp[i][cst]);		
	}
	
	debug(dp[4][cst])
	cout << ans << endl;
	return 0;
}