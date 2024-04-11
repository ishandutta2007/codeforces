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

const ll MAXN = 1e2 + 10;

int dp[MAXN][MAXN][2][2];

inline void fmax(int& a, int x) {
	a = max(a, x);
}

inline void fmin(int& a, int x) {
	a = min(a, x);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	dp[0][0][0][0] = dp[0][0][0][1] = 1;

	for (int i = 0; i < MAXN; i++) {
		for (int j = 0; j < MAXN; j++) {
			if (i + j == 0) continue;

			for (int a = 0; a < 2; a++) {
				dp[i][j][a][1] = 1;
				if (i) fmax(dp[i][j][a][0], dp[i - 1][j][a][1]), fmin(dp[i][j][a][1], dp[i - 1][j][a][0]);
				if (j) fmax(dp[i][j][a][0], dp[i][j - 1][a ^ 1][1]), fmin(dp[i][j][a][1], dp[i][j - 1][a][0]);
				
			}
		}
	}


	int t;
	cin >> t;
	while (t--) {
		int c[2] = {0, 0}, n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			c[x & 1]++;
		}

		cout << (dp[c[0]][c[1]][0][0] ? "Alice" : "Bob") << endl;
	}
	return 0;
}