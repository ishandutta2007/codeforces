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
 
const ll MAXN = 1e4 + 10;
const ll MAXK = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXK] = {0}, narr[MAXN], pref[MAXN][MAXK], sc[MAXN][MAXK], suff[MAXN][MAXK], tarr[MAXN];

int main() {
	fast_io;
	ll n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		ll k;
		cin >> k;
		narr[i] = k;
		pref[i][0] = suff[i][0] = 0;
		for (int j = 1; j <= k; j++) cin >> tarr[j];
		for (int j = 1; j <= k; j++) pref[i][j] = pref[i][j - 1] + tarr[j];
		reverse(tarr + 1, tarr + k + 1);	
		for (int j = 1; j <= k; j++) suff[i][j] = suff[i][j - 1] + tarr[j];

		sc[i][0] = 0;
		for (int j = 1; j <= k; j++) {
			for (int p = 0; p <= j; p++) {
				sc[i][j] = max(sc[i][j], pref[i][p] + suff[i][j - p]);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--) {
		for (ll k = 0; k <= m; k++) {
			for (int j = 0; j <= min(k, narr[i]); j++) dp[i][k] = max(dp[i][k], sc[i][j] + dp[i + 1][k - j]);
		}
	}

	cout << dp[0][m] << endl;
	return 0;
}