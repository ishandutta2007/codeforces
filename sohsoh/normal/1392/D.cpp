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
const ll INF = 8e15;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][2][2];
string s;

// 0: L
// 1: R
//
// f : KH
// s : G
ll solve() {
	ll n;
	cin >> n >> s;
	
	dp[1][0][0] = int(s[0] == 'R') + int(s[1] == 'R');
	dp[1][0][1] = dp[1][1][1] = dp[1][1][0] = INF;
	for (int i = 2; i < n; i++) {
		if (s[i] == 'L') {
			dp[i][0][0] = dp[i - 1][0][1];
			dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]);
			dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]) + 1;
			dp[i][1][1] = dp[i - 1][1][0] + 1;
		} else {
			dp[i][0][0] = dp[i - 1][0][1] + 1;
                        dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]) + 1;
                        dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
                        dp[i][1][1] = dp[i - 1][1][0];
		}

	}

	ll ans = INF;
	ans = min(ans, min(dp[n - 1][1][0], dp[n - 1][1][1])); 
	
	dp[1][1][1] = int(s[0] == 'L') + int(s[1] == 'L');
	dp[1][0][1] = dp[1][0][0] = dp[1][1][0] = INF;
		
	for (int i = 2; i < n; i++) {
		if (s[i] == 'L') {
			dp[i][0][0] = dp[i - 1][0][1];
			dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]);
			dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]) + 1;
			dp[i][1][1] = dp[i - 1][1][0] + 1;
		} else {
			dp[i][0][0] = dp[i - 1][0][1] + 1;
                        dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]) + 1;
                        dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
                        dp[i][1][1] = dp[i - 1][1][0];
		}

	}

	//ll ans = INF;
	ans = min(ans, min(dp[n - 1][0][0], dp[n - 1][0][1])); 
	dp[1][0][1] = int(s[0] == 'L') + int(s[1] == 'R');
	dp[1][0][0] = dp[1][1][1] = dp[1][1][0] = INF;
		
	for (int i = 2; i < n; i++) {
		if (s[i] == 'L') {
			dp[i][0][0] = dp[i - 1][0][1];
			dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]);
			dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]) + 1;
			dp[i][1][1] = dp[i - 1][1][0] + 1;
		} else {
			dp[i][0][0] = dp[i - 1][0][1] + 1;
                        dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]) + 1;
                        dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
                        dp[i][1][1] = dp[i - 1][1][0];
		}

	}

	//ll ans = INF;
	ans = min(ans, min(dp[n - 1][1][0], dp[n - 1][0][1]));
       	ans = min(ans, dp[n - 1][0][0]);	

	dp[1][1][0] = int(s[0] == 'R') + int(s[1] == 'L');
	dp[1][0][1] = dp[1][1][1] = dp[1][0][0] = INF;
		
	for (int i = 2; i < n; i++) {
		if (s[i] == 'L') {
			dp[i][0][0] = dp[i - 1][0][1];
			dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]);
			dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]) + 1;
			dp[i][1][1] = dp[i - 1][1][0] + 1;
		} else {
			dp[i][0][0] = dp[i - 1][0][1] + 1;
                        dp[i][0][1] = min(dp[i - 1][1][0], dp[i - 1][1][1]) + 1;
                        dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][0][1]);
                        dp[i][1][1] = dp[i - 1][1][0];
		}

	}

	//ll ans = INF;
	ans = min(ans, min(dp[n - 1][1][0], dp[n - 1][1][1]));
	ans = min(ans, dp[n - 1][0][1]);
	cout << ans << endl;
	return 0;
}

int main() {
	fast_io;
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}	

	return 0;
}