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

const ll MAXN = 5e3 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

short dp[MAXN][MAXN];
string s, t;
int n, m;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	cin >> s >> t;
	s = '.' + s;
	t = '.' + t;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s[i] == t[j]) dp[i][j] = max(2, 2 + dp[i - 1][j - 1]);
			dp[i][j] = max(int(dp[i][j]), dp[i - 1][j] - 1);
			dp[i][j] = max(int(dp[i][j]), dp[i][j - 1] - 1);
			dp[i][j] = max(int(dp[i][j]), dp[i - 1][j - 1] - 2);
		}
	} 

	ll ans = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			ans = max(ll(dp[i][j]), ans);
		}
	}

	cout << ans << endl;
	return 0;
}