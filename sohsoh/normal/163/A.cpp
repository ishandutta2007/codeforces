/*
	alsdjkflasdjf
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
const ll MAXK = 900;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

string s, t;
ll dp[MAXN][MAXN] = {0};

ll mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}
	
int main() {
	cin >> s >> t;
	ll n = s.size(), m = t.size();
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			dp[i][j] = dp[i][j + 1];
			if (s[i] == t[j]) mkey(dp[i][j] += dp[i + 1][j + 1]), mkey(dp[i][j] += 1);
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) mkey(ans += dp[i][0]);
	cout << ans << endl;
}