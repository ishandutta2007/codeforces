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
 
const ll MAXN = 200 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN][MAXN] = {0};
ll cnt[3];
ll A[3][MAXN];

int main() {
	fast_io;
	cin >> cnt[0] >> cnt[1] >> cnt[2];
	for (int i = 1; i <= cnt[0]; i++) cin >> A[0][i];
	for (int i = 1; i <= cnt[1]; i++) cin >> A[1][i];
	for (int i = 1; i <= cnt[2]; i++) cin >> A[2][i];
	sort(A[0] + 1, A[0] + 1 + cnt[0]);
	sort(A[1] + 1, A[1] + 1 + cnt[1]);
	sort(A[2] + 1, A[2] + 1 + cnt[2]);

	for (int i = 0; i <= cnt[0]; i++) {
		for (int j = 0; j <= cnt[1]; j++) {
			for (int k = 0; k <= cnt[2]; k++) {
				if (i > 0 && j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k] + A[0][i] * A[1][j]);
				if (i > 0 && k > 0) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k - 1] + A[0][i] * A[2][k]);
				if (k > 0 && j > 0) dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][k - 1] + A[2][k] * A[1][j]);
			}
		}
	}

	cout << dp[cnt[0]][cnt[1]][cnt[2]] << endl;
}