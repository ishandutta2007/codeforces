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

ll n, A[MAXN], B[MAXN], C[MAXN], dp[MAXN][3];

int main() {
	fast_io;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	for (int i = 1; i <= n; i++) cin >> B[i];
	for (int i = 1; i <= n; i++) cin >> C[i];
	dp[1][0] = A[1];
	dp[1][1] = B[1];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][0] + B[i], dp[i - 1][1] + A[i]);
		dp[i][1] = max(dp[i - 1][0] + C[i], dp[i - 1][1] + B[i]);
	}

	cout << dp[n][0] << endl;
}