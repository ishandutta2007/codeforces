/*
    Soheil Mohammadkhani
    OK, im back :)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
 
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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN], ps[MAXN];

int main() {
	dp[0] = 1;
	ll t, k;
	cin >> t >> k;
	for (int i = 1; i < MAXN; i++) {
		dp[i] = dp[i - 1];
		if (i - k >= 0) dp[i] += dp[i - k];
		dp[i] %= MOD;
	}

	ps[0] = 0;
	for (int i = 1; i < MAXN; i++) ps[i] = (ps[i - 1] + dp[i]) % MOD;
	//alog(dp, n)
	while (t--) {
		ll l, r;
		cin >> l >> r;
		cout << (ps[r] - ps[l - 1] + MOD) % MOD << endl;
	}
	fast_io;
}