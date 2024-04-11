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

const ll MAXN = 5000 + 10;
const ll INF = 1e8;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int A[MAXN], dp[MAXN][MAXN][2], n;

inline void upd(int& a, int b) {
	a = min(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> A[i];
	
	for (int i = 0; i < MAXN; i++) dp[0][i][0] = dp[0][i][1] = INF;
	dp[0][0][0] = dp[0][0][1] = 0;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < MAXN; j++) {
			dp[i][j][0] = dp[i][j][1] = INF;
			if (j > n) continue;

			if (A[i] == 1) {
				upd(dp[i][j][0], dp[i - 1][j + 1][0] + j);
				if (j) upd(dp[i][j][1], dp[i - 1][j - 1][1] + j);
			} else {
				upd(dp[i][j][0], dp[i - 1][j][0] + j);
				upd(dp[i][j][1], dp[i - 1][j][1] + j);
				if (j) upd(dp[i][j][0], dp[i - 1][j - 1][0] + j);
				upd(dp[i][j][1], dp[i - 1][j + 1][1] + j);
			}
		}
		
		upd(dp[i][0][0], dp[i][0][1]);
		upd(dp[i][0][1], dp[i][0][0]);
	}
	
	cout << min(dp[n][0][1], dp[n][0][0]) << endl;
	return 0;
}