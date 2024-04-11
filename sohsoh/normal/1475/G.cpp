#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int dp[MAXN], A[MAXN], cnt[MAXN], n;

inline void solve() {
	memset(dp, 0, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	sort(A + 1, A + n + 1);
	
	for (int i = 1; i <= n; i++) {
		int x = A[i];
		int sq = sqrt(x);
		int ndp = 1;
		for (int j = 1; j <= sq; j++) {
			if (x % j == 0) {
				ndp = max(ndp, 1 + dp[x / j]);
				ndp = max(ndp, 1 + dp[j]);
			}		
		}

		dp[x] = ndp;
	}

	cout << n - *max_element(dp, dp + MAXN) << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}