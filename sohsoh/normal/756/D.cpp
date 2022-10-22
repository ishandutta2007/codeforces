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

const ll MAXN = 5e3 + 10;
const ll SIG = 26;
const ll MOD = 1e9 + 7;

ll C[MAXN][MAXN], S[MAXN], dp[SIG][MAXN], n;
string s;

inline void mkay(ll& a) {
	if (a >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	s = "." + s;

	for (int i = 0; i <= n; ++i) {
		C[0][i] = C[i][i] = 1;
		for (int j = 1; j < i; ++j)
			C[j][i] = (C[j - 1][i - 1] + C[j][i - 1]) % MOD;
	}

	for (int i = 1; i <= n; i++) {
		int c = s[i] - 'a';
		
		for (int j = n; j > 0; j--) {
			mkay(S[j] -= dp[c][j]);
			mkay(dp[c][j] = S[j - 1] - dp[c][j - 1]);
			mkay(S[j] += dp[c][j]);
		}

		mkay(dp[c][1] += 1);
		mkay(S[1] += 1);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + S[i] * C[i - 1][n - 1]) % MOD;
	mkay(ans);

	cout << ans << endl;
	return 0;
}