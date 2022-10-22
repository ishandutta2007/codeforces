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
 
const ll MAXN = 3e5 + 10;
const ll MAXM = 100 + 10;
const ll INF = 8e18;
ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll LOG = 22;

ll dp[MAXN][MAXM] = {0};
ll tpow[LOG], A[LOG];

ll mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int main() {
	fast_io;
	tpow[0] = 1;
	for (int i = 1; i < LOG; i++) tpow[i] = 2ll * tpow[i - 1];
	dp[0][0] = 1;
	string s;
	cin >> s >> MOD;
	ll n = s.size();
	for (int i = 0; i < s.size(); i++) A[i] = s[i] - '0';
	for (ll i = 1; i < tpow[n]; i++) {
		ll pr = i;
		bool chk[10] = {false};
		for (int j = 0; j < LOG; j++) {
			if (chk[A[j]]) continue;
			if ((i ^ tpow[j]) < i) {
				i ^= tpow[j];
				if (i == 0 && A[j] == 0) {
					i ^= tpow[j];
					continue;
				}

				for (int k = 0; k < MOD; k++) {
					ll md = (k * 10 + A[j]) % MOD;
					dp[pr][md] += dp[i][k];
				}

				i ^= tpow[j];
				chk[A[j]] = true;
			}
		}	
	}

	cout << dp[tpow[n] - 1][0] << endl;
	return 0;
}