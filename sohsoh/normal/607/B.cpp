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
 
const ll MAXN = 5e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN], A[MAXN];
ll n;

int main() {
	fast_io;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> A[i];
	for (int i = 0; i < MAXN; i++) dp[0][i] = 0, dp[1][i] = 1;
	
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= n - i; j++) {
			dp[i][j] = dp[i - 1][j + 1] + 1;
			if (A[j] == A[j + 1]) dp[i][j] = min(dp[i][j], 1 + dp[i - 2][j + 2]);
			for (int k = j + 2; k < i + j; k++) {
				if (A[j] == A[k]) dp[i][j] = min(dp[i][j], dp[k - j - 1][j + 1] + dp[i + j - 1 - k][k + 1]);
			}
		}
	}
		
	cout << dp[n][0] << endl;
	return 0;
}