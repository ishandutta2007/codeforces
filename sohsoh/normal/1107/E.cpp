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
 
ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}
 
const ll MAXN = 1e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll n, A[MAXN], dp[MAXN][MAXN][MAXN]; // max score by removing [L, R]
string s;

void upd(ll& a, ll b) {
	a = max(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	s = '.' + s;	
	for (int L = 0; L < MAXN; L++) for (int R = 0; R < MAXN; R++) for (int O = 1; O < MAXN; O++) dp[L][R][O] = -INF;
	for (int i = 1; i <= n; i++) cin >> A[i], dp[i][i][0] = A[1], dp[i][i][1] = 0;
	for (int sz = 2; sz <= n; sz++) {
		for (int L = 1; L <= n - sz + 1; L++) {
			int R = L + sz - 1;
			for (int k = 1; k <= n; k++) {
				if (s[L] == s[R]) upd(dp[L][R][k], dp[L][R - 1][k - 1]);
				for (int lst = L; lst < R; lst++) {
					if (s[L] == s[R]) upd(dp[L][R][k], dp[L][lst][k - 1] + dp[lst + 1][R - 1][0]);
					upd(dp[L][R][k], dp[L][lst][k] + dp[lst + 1][R][0]);
				}


				upd(dp[L][R][0], dp[L][R][k] + A[k]);
			}
		}
	}
	
	cout << dp[1][n][0] << endl;

	return 0;
}