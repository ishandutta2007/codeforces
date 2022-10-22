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

const ll MAXN = 1e6 + 10;

int dp[MAXN][2][2], n;
bool G[MAXN][2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			G[j][i] = (c == '1');
			cnt += G[j][i];
		}
	}	

	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k >= 0; k--) {
				if (G[i + 1][j] && G[i][j ^ 1] && (k ^ 1)) dp[i][j][k] = min(dp[i + 1][j][0], dp[i + 1][j ^ 1][1]) + 1;
				else if (G[i + 1][j]) dp[i][j][k] = dp[i + 1][j][0];
				else if (G[i][j ^ 1] && (k ^ 1)) dp[i][j][k] = dp[i + 1][j ^ 1][0];
				else dp[i][j][k] = dp[i + 1][j][0];
			}

			dp[i][j][0] = min(dp[i][j][0], dp[i][j][1] + 1);
		}
	}

	cout << cnt - dp[1][0][0] << endl;
	return 0;
}