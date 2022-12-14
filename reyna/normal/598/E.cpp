//In the name of God
// (c) Silver soul 49
// What i'll engrave in this place is my soul!!!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, e) for(int i = (s); i < (e); i++)
#define x first
#define y second

typedef long long ll;
typedef pair<int, int> pii;

template<class P, class Q> inline P smin (P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax (P &a, Q b) { if (a < b) a = b; return a; }


int pw (int a, int b, int mod) { return (b? pw(1LL * a * a % mod, b >> 1, mod) * 1LL * (b & 1? a : 1) % mod: 1); }
int lcm (int x, int y) { return min(x, y)? x / __gcd(x, y) * y: max(x, y); }

/*******************************************************************************************************/

const int maxN = 55;
const int mod = 0;
const int base = 1000 * 1000 + 3;
const int oo = 1e9 + 49;

int dp[maxN][maxN][maxN];

int32_t main () {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, 63, sizeof dp);
	dp[1][1][1] = 0;
	dp[1][1][0] = 0;
	for (int i = 1; i < 31; i++)
		for (int j = 1; j < 31; j++) if (i != 1 || j != 1) {
			dp[i][j][0] = 0;
			if (i * j < maxN) dp[i][j][i * j] = 0;
			for (int k = 0; k < min(maxN, i * j); k++) {
				for (int h = 1; h < i; h++)
					for (int l = 0; l <= k; l++)
						smin(dp[i][j][k], dp[h][j][l] + dp[i - h][j][k - l] + j * j);
				for (int v = 1; v < j; v++)
					for (int l = 0; l <= k; l++)
						smin(dp[i][j][k], dp[i][v][l] + dp[i][j - v][k - l] + i * i);
			}
		}
	int tc; cin >> tc;
	while (tc--) {
		int n, m, k; cin >> n >> m >> k;
		cout << dp[n][m][k] << '\n';	
	}
}