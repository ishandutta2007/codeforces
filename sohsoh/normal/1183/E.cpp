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
 
const ll MAXN = 2e2 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

ll dp[MAXN][MAXN] = {0}, F[MAXN][26], tmp[26] = {0}, n, k;
ll cst[MAXN] = {0};
// ind, len

void overflow_ctrl(ll& a) {
	a = min(a, k);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	cin >> n >> k >> s;
	s = 'N' + s + 'N';
	for (int i = 1; i <= n + 1; i++) {
		for (int j = 0; j < 26; j++) F[i][j] = tmp[j];
		tmp[s[i] - 'a'] = i;
	}

	dp[1][0] = dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				dp[i][j] = 1;
				continue;
			}

			for (int c = 0; c < 26; c++) {
				overflow_ctrl(dp[i][j] += dp[F[i][c]][j - 1]);
			}
		}
	}

	for (int i = n; i >= 1; i--) {
		for (int c = 0; c < 26; c++) {
			overflow_ctrl(cst[n - i] += dp[F[n + 1][c]][i]);
		}
	}

	cst[n]++;	

	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		ll x = min(k, cst[i]);
		k -= x;
		ans += i * x;
	}


	if (k > 0) return cout << -1 << endl, 0;
	cout << ans << endl;
	return 0;
}