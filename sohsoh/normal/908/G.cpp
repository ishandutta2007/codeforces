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

const ll MAXN = 700 + 10;
const ll MOD = 1e9 + 7;
const ll SIG = 10;

string s;
ll n, dp[MAXN][MAXN][2], A[MAXN];

inline void mkay(ll& a) {
	if (a >= MOD) a -= MOD;

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	n = s.size();
	s = '.' + s;

	for (int i = 1; i <= n; i++) A[i] = s[i] - '0';

	ll fans = 0;
	for (int ind = 1; ind < SIG; ind++) {
		ll ans = 0;
		for (int j = 0; j < MAXN; j++)
			for (int k = 0; k < MAXN; k++)
				for (int t = 0; t < 2; t++)
					dp[j][k][t] = 0;

		for (int i = 0; i <= A[1]; i++) {
			int c = 0;
			if (i >= ind) c = 1;
			if (i == A[1]) dp[1][c][1]++;
			else dp[1][c][0]++;
		}

		for (int i = 1; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				for (int c = 0; c < 2; c++) {
					int t = (c ? A[i + 1] : 9);

					for (int k = 0; k <= t; k++) {
						mkay(dp[i + 1][j + (k >= ind)][c && (k == t)] += dp[i][j][c]);
					}
				}
			} 
		}


	 	ll pw = 0;
		for (int i = 0; i <= n; i++) {
			mkay(ans += (dp[n][i][0] + dp[n][i][1]) * pw % MOD);
			pw = (pw * 10 + 1) % MOD;
		}

		fans += ans % MOD;
	}

	cout << fans % MOD << endl;
	return 0;
}