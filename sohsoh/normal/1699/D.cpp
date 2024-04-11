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

int dp[MAXN], ps[MAXN][MAXN], n, maj[MAXN][MAXN], A[MAXN];

inline int solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++)
			ps[i][j] = ps[i - 1][j];

		cin >> A[i];
		ps[i][A[i]]++;
	}

	for (int l = 1; l <= n; l++) {
		maj[l][l] = l;
		for (int r = l + 1; r <= n; r++)
			maj[l][r] = (ps[r][A[r]] - ps[l - 1][A[r]] > ps[r][maj[l][r - 1]] - ps[l - 1][maj[l][r - 1]] ? A[r] : maj[l][r - 1]);
	}

	A[n + 1] = 0;
	for (int i = 1; i <= n + 1; i++) {
		dp[i] = -MAXN;
		for (int j = 0; j < i; j++) {
			int m = maj[j + 1][i - 1];
			if (j == 0 || i == n + 1 || A[j] == A[i]) {
				if (j == i - 1 || (ps[i - 1][m] - ps[j][m] <= (i - j - 1) / 2 && (i - j - 1) % 2 == 0)) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
	}

	cout << max(0, dp[n + 1] - 1) << endl;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
	return 0;
}