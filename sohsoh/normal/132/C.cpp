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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

// 0: right, 1: left
bool dp[110][210][60][2] = {0};
ll n;
string s;
ll cst = 103;


int main() {
	fast_io;
	cin >> s >> n;
	s = 'N' + s;
	for (int i = 0; i < 60; i += 2) dp[0][cst][i][0] = true;
	for (int i = 1; i <= s.size(); i++) {
		for (int p = 1; p < 208; p++) {
			for (int k = 0; k < 59; k++) {
				if (s[i] == 'F') {
					dp[i][p][k][0] |= dp[i - 1][p - 1][k][0];
					dp[i][p][k][1] |= dp[i - 1][p + 1][k][1];	
					if (k > 0) {
						dp[i][p][k][0] |= dp[i - 1][p][k - 1][1];
						dp[i][p][k][1] |= dp[i - 1][p][k - 1][0];	
					}
				} else {	
					dp[i][p][k][0] |= dp[i - 1][p][k][1];
					dp[i][p][k][1] |= dp[i - 1][p][k][0];
					if (k > 0) {	
						dp[i][p][k][0] |= dp[i - 1][p - 1][k - 1][0];
						dp[i][p][k][1] |= dp[i - 1][p + 1][k - 1][1];
					}
				} 	
			}
		}
	}

	
	ll ans = 0;
	for (int i = 0; i < 210; i++) if (dp[s.size() - 1][i][n][0] || dp[s.size() - 1][i][n][1]) ans = max(ans, abs(i - cst));	
	cout << ans << endl;
	return 0;
}