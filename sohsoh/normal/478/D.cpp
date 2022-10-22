/*
    Soheil Mohammadkhani
    final test contest on vim
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

const ll MAXN = 2e5 + 10;
const ll MAXK = 900;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN], dp2[MAXN];

ll mkey(ll& x) {
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
	return x;
}

int main() {
	ll r, g, n;
	cin >> r >> g;
	n = r + g;
	ll mx = 0;
	ll h = 1;
	while (mx + h <= n) {
		mx += h;
		h++;
	}

	h--;
	dp2[0] = 1;
	for (int k = 1; k <= h; k++) {
		for (int i = 0; i < MAXN; i++) dp[i] = dp2[i];
		for (int i = 0; i + k < MAXN; i++) {
			mkey(dp[i + k] += dp2[i]);
		}

		for (int i = 0; i < MAXN; i++) dp2[i] = dp[i];
	}
	
	ll ans = 0;
	while (mx - g <= r) {
		mkey(ans += dp[g]);
		g--;
	}

	cout << ans << endl;
}