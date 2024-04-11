/*
	:]
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
const ll MAXK = 5e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll A[MAXN], dp[MAXK][MAXK] = {0};

int main() {
	fast_io;
	ll n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> A[i];
	sort(A, A + n);
	ll l_n = n % k;
	ll s_n = k - l_n;
	ll s_l = n / k, l_l = n / k + 1;

	for (int i = 0; i < MAXK; i++) {
		for (int j = 0; j < MAXK; j++) {
			if ((i == 0 && j == 0) || s_l * i + l_l * j > n) continue;
			dp[i][j] = INF;
			ll ind = s_l * i + l_l * j - 1;
			if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + A[ind] - A[ind - s_l + 1]);
			if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + A[ind] - A[ind - l_l + 1]);

		}
	}

	cout << dp[s_n][l_n] << endl;
}