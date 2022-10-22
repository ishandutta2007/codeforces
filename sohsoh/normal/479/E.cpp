/*
    Soheil Mohammadkhani
    OK, im back :)
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
 
const ll MAXN = 5000 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, a, b, k, dp[MAXN][MAXN], ps[MAXN];

ll mkey(ll &a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int main() {
	fast_io;
	cin >> n >> a >> b >> k;
	fill(dp[0], dp[0] + MAXN, 1); 
	for (int i = 1; i <= k; i++) {
		ps[0] = 0;
		for (int j = 1; j <= n; j++) mkey(ps[j] = ps[j - 1] + dp[i - 1][j]);
		for (int j = 1; j <= n; j++) {
			ll d = abs(j - b) - 1;
			mkey(dp[i][j] = ps[min(j + d, n)] - ps[max(j - d - 1, 0ll)]);
			mkey(dp[i][j] -= dp[i - 1][j]);
		}
	}
	
	cout << dp[k][a] << endl;;
}