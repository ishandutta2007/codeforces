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

const ll MAXN = 1e6 + 10;
const ll INF = 1e9;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dp[MAXN], n, k, p, x, y;
string A;

inline int solve() {
	fill(dp, dp + n + 10, 0);
	cin >> n >> p >> k >> A >> x >> y;
	A = 'C' + A;
	for (int i = n; i > 0; i--) {
		dp[i] = dp[i + k];
		if (A[i] == '0') dp[i] += x;
	}

	int ans = INF;
	for (int i = p; i <= n; i++) ans = min(ans, dp[i] + (i - p) * y);
	cout << ans << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}