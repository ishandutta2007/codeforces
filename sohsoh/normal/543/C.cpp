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

const ll MAXN = 20;
const ll INF = 1e9;

int n, m, dp[1 << MAXN], f[MAXN][MAXN], fmask[MAXN][MAXN], C[MAXN][MAXN];
string S[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> S[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> C[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int mx = 0;
			for (int k = 0; k < n; k++) {
				if (S[k][j] != S[i][j]) continue;
				mx = max(mx, C[k][j]);
				f[i][j] += C[k][j];
				fmask[i][j] ^= (1 << k);
			}

			f[i][j] -= mx;
		}
	}

	for (int mask = 1; mask < (1 << n); mask++) {
		dp[mask] = INF;
		int ind = __builtin_ctz(mask);

		for (int j = 0; j < m; j++) {
			dp[mask] = min(dp[mask], dp[mask ^ (1 << ind)] + C[ind][j]);
			dp[mask] = min(dp[mask], dp[mask & (mask ^ fmask[ind][j])] + f[ind][j]);
		}
	}

	cout << dp[(1 << n) - 1] << endl;
	return 0;
}