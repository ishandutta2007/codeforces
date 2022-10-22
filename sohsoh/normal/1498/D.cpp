#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define all(x)                      (x).begin(),(x).end()
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define debug(x)                    cerr << #x << ": " <<  x << endl;
#define int 			    ll

const ll MAXM = 1e5 + 10;
const ll MAXN = 2e2 + 10;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;
const ll W = 1e5;

int n, m;
int dp[MAXN][MAXM];

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int j = 0; j < MAXM; j++) dp[0][j] = INF;
	dp[0][0] = 0;
	
	for (int i = 1; i <= n; i++) {
		int t, x, y;
		cin >> t >> x >> y;
		for (int j = 0; j <= m; j++) {
			dp[i][j] = INF;

			if (t == 1) {
				ll c = (x + W - 1) / W;
				if (j >= c) {
					dp[i][j] = min(dp[i][j], dp[i][j - c] + 1);
					if (dp[i - 1][j - c] < INF) dp[i][j] = 1; 
				}

				if (dp[i - 1][j] < INF) dp[i][j] = 0;
			} else {
				int jp = j * W / x;
				if ((jp * x + W - 1) / W == j) {
					dp[i][j] = min(dp[i][j], dp[i][jp] + 1);
					if (dp[i - 1][jp] < INF) dp[i][j] = 1;
				}

				if (dp[i - 1][j] != INF) dp[i][j] = 0;

			}
	
			
			if (dp[i][j] > y) dp[i][j] = INF;	
		}
	}

	for (int i = 1; i <= m; i++) {
		bool flag = true;
		for (int j = 1; j <= n; j++) {
			if (dp[j][i] < INF) {
				cout << j << sep;
				flag = false;
				break;
			}
		}

		if (flag) cout << -1 << sep;
	}

	cout << endl;
	return 0;
}