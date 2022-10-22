#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define all(x)			(x).begin(),(x).end()
#define X			first
#define Y			second
#define sep			' '
#define endl			'\n'
#define debug(x)		cerr << #x << ": " <<  x << endl;

const ll MAXN = 2e2 + 10;
const ll INF = 1e18;

ll dp[MAXN][MAXN * MAXN], A[MAXN], B[MAXN], n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n + 5; i++)
			for (int j = 0; j < (n + 5) * MAXN; j++)
				dp[i][j] = INF;

		for (int i = 1; i <= n; i++) cin >> A[i];
		for (int i = 1; i <= n; i++) cin >> B[i];

		dp[0][0] = 0;
		ll tans = 0, ps = 0, fans = INF;

		for (int i = 1; i <= n; i++) {
			tans += A[i] * A[i] * (n - 1);
			tans += B[i] * B[i] * (n - 1);
			ps += A[i];
			ps += B[i];

			for (int s = 0; s < MAXN * (n + 2); s++) {
				if (s >= A[i] && ps - s >= B[i]) dp[i][s] = min(dp[i][s], dp[i - 1][s - A[i]] + (s - A[i]) * A[i] + (ps - s - B[i]) * B[i]);
				if (s >= B[i] && ps - s >= A[i]) dp[i][s] = min(dp[i][s], dp[i - 1][s - B[i]] + (s - B[i]) * B[i] + (ps - s - A[i]) * A[i]);
			
				if (i == n) fans = min(fans, dp[i][s]);
			}
		}	

		cout << tans + fans * 2 << endl;
	}
	return 0;
}