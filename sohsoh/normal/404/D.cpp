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
 
const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][2][2] = {0};
ll ans[MAXN] = {0};

ll mkey(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

ll mkey(ll a) {	
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
	return a;
}

int main() {
	fast_io;
	string s;
	cin >> s;
	s = 'N' + s;
	if (s[1] == '*' || s[1] == '?') dp[0][0][1] = 1;
	if (s[1] == '0' || s[1] == '1' || s[1] == '2' || s[1] == '?') dp[0][0][0] = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '*' || s[i] == '?') dp[i][1][0] = dp[i][1][1] = mkey(dp[i - 1][0][1] + dp[i - 1][1][1]);
		if (s[i] == '?') dp[i][0][1] = dp[i][0][0] = mkey(dp[i - 1][0][0] + dp[i - 1][1][0]);
		if (s[i] == '0') dp[i][0][0] = dp[i - 1][0][0];
		if (s[i] == '1') dp[i][0][1] = dp[i - 1][0][0], dp[i][0][0] = dp[i - 1][1][0];
		if (s[i] == '2') dp[i][0][1] = dp[i - 1][1][0];
	}
	
	cout << mkey(dp[s.size() - 1][1][0] + dp[s.size() - 1][0][0]) << endl;
	return 0;
}