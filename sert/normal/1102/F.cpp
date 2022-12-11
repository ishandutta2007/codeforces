#pragma GCC diagnostic ignored "-Wunused-result"
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 16;
const int M = (1 << N);
//const ll INF = (ll)1e18 + 41;
const int INF = (int)1e9 + 41;
const ll MD = (ll)1e9 + 7;
bool D = false;

int dp[N][N][M];
int nx[N][N];

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	if (n == 1) {
		int ans = INF;
		for (int i = 1; i < m; i++) {
			ans = min(ans, abs(a[0][i] - a[0][i - 1]));
		}
		cout << ans << "\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int msk = 0; msk < (1 << n); msk++) {
				dp[i][j][msk] = 0;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			nx[i][j] = INF;
			for (int x = 0; x < m; x++) {
				nx[i][j] = min(nx[i][j], abs(a[i][x] - a[j][x]));
			}
			//cout << "nx " << i << " " << j << " = " << nx[i][j] << "\n";
		}
	}

	for (int i = 0; i < n; i++) {
		dp[i][i][1 << i] = INF;
	}

	for (int msk = 1; msk < (1 << n); msk++) {
		for (int f = 0; f < n; f++) {
			for (int l = 0; l < n; l++) {
				int cur_dp = dp[f][l][msk];
				if (cur_dp == 0) continue;
				//if ((msk & (1 << f)) == 0 && (msk & (1 << l)) == 0) continue;

				for (int x = 0; x < n; x++) {
					if (msk & (1 << x)) continue;
					int new_msk = (msk | (1 << x));
					dp[f][x][new_msk] = max(dp[f][x][new_msk], min(cur_dp, nx[l][x]));
				}
			}
		}
	}

	int ans = 0;
	for (int f = 0; f < n; f++) {
		for (int l = 0; l < n; l++) {
			int cur = dp[f][l][(1 << n) - 1];
			if (cur == 0) continue;

			for (int j = 0; j + 1 < m; j++) {
				cur = min(cur, abs(a[l][j] - a[f][j + 1]));
			}

			ans = max(ans, cur);
		}		
	}

	cout << ans << "\n";
}

int main() {
#ifdef LOCAL
	freopen("a.in", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tst = 1;
	//scanf("%d", &tst);
	//cin >> tst;
#ifdef MADE_BY_SERT
	D = true;	
	tst = 3;
	while (tst--) {
		solve();
	}
#else
	while (tst--) solve();
#endif
}