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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e16;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[31][31][51];

int main() {
	fast_io;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 31; j++) {
			for (int k = 0; k < 51; k++) {
				dp[i][j][k] = INF;
				if (i * j == k) dp[i][j][k] = 0;
			}

			dp[i][j][0] = 0;
		}
	}

	for (ll i = 0; i < 31; i++) {
		for (ll j = 0; j < 31; j++) {
			for (ll k = 0; k < 51; k++) {
				for (ll a = 1; a < i; a++) 
					for (int k2 = 0; k2 <= k; k2++) dp[i][j][k] = min(dp[i][j][k], dp[a][j][k2] + dp[i - a][j][k - k2] + j * j);
				for (ll a = 1; a < j; a++)
				        for (int k2 = 0; k2 <= k; k2++)	dp[i][j][k] = min(dp[i][j][k], dp[i][a][k2] + dp[i][j - a][k - k2] + i * i);
						
			}
		}
	}


	ll t;
	cin >> t;
	while (t--) {
		ll n, m, k;
		cin >> n >> m >> k;
		cout << dp[n][m][k] << endl;
	}
}