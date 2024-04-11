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

const ll MAXN = 1e6 + 10;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n, A[MAXN], ps[MAXN];
bool dp[MAXN][4];

inline int solve() {
	for (int i = 0; i < n + 3; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = false;
		ps[i] = 0;
	}

	cin >> n;
	int x = 0;
	for (int i = 1; i <= n; i++) cin >> A[i], x ^= A[i], ps[i] = x;
	if (x == 0) return cout << "YES" << endl, 0;
	
	dp[0][0] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			if ((ps[i] ^ ps[j]) == x) {
				dp[i][1] |= dp[j][0];
				dp[i][2] |= dp[j][1];
				dp[i][3] |= dp[j][2];
			}
		}
	}

	if (dp[n][3]) return cout << "YES" << endl, 0;
	cout << "NO" << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}