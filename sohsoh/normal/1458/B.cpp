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

const ll MAXN = 100 + 3;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n;
int dp[MAXN][MAXN][MAXN * MAXN]; // ind, k, cap

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int s = 0;

	for (int i = 0; i < MAXN; i++) for (int j = 0; j < MAXN; j++) for (int k = 0; k < MAXN * MAXN; k++) dp[i][j][k] = -(int)1e9;
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		s += b;

		for (int k = 0; k <= n; k++) {
			for (int cap = 0; cap < MAXN * MAXN; cap++) {
				dp[i][k][cap] = dp[i - 1][k][cap];
				if (k > 0 && cap >= a) dp[i][k][cap] = max(dp[i][k][cap], dp[i - 1][k - 1][cap - a] + b);
			}
		}		
	}

	cout << setprecision(10) << fixed;
	for (int k = 1; k <= n; k++) {
		ld ans = 0;
		for (int cap = 0; cap < MAXN * MAXN; cap++) {
			ld tans = dp[n][k][cap];
			tans += min(ld(cap - dp[n][k][cap]), (ld(s - dp[n][k][cap]) / 2.0));	
			if (k == 1 && tans == 8.5 && ans != 8.5) debug(s)
			ans = max(ans, tans);
		}

		cout << ans << sep;
	}

	cout << endl;
	return 0;
}