#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < (N); i++)
#define aint(a) (a).begin(), (a).end()

using ll = long long;
using i_i = tuple<int, int>;

const int INF = INT_MAX / 2;

int dp[5000][3], _dp[5000][3];

int main() {
	int N; cin >> N;
	vector<int> a(N);
	rep(i, N) {
		scanf("%d", &a[i]);
	}
	int n = (N + 1) / 2;
	rep(x, n + 1) rep(p, 3) dp[x][p] = INF;
	dp[0][2] = dp[1][0] = 0;
	for (int i = 1; i < N; i++) {
		rep(x, n + 1) rep(p, 3) _dp[x][p] = INF;
		rep(x, n + 1) {
			rep(p, 3) {
				int z = dp[x][p];
				if (z == INF) {
					continue;
				}
				if (p == 0) {
					int d = max(0, a[i] - a[i - 1] + 1);
					_dp[x][1] = min(_dp[x][1], z + d);
				}
				if (p == 1) {
					_dp[x][2] = min(_dp[x][2], z);
					int d1 = max(0, a[i - 1] - a[i - 2] + 1);
					int d2 = max(0, a[i - 1] - a[i] + 1);
					int d = max(0, d2 - d1);
					_dp[x + 1][0] = min(_dp[x + 1][0], z + d);
				}
				if (p == 2) {
					_dp[x][2] = min(_dp[x][2], z);
					int d = max(0, a[i - 1] - a[i] + 1);
					_dp[x + 1][0] = min(_dp[x + 1][0], z + d);
				}
			}
		}
		rep(x, n + 1) rep(p, 3) dp[x][p] = _dp[x][p];
		/*
		rep(x, N + 1) {
			rep(p, 3) {
				cout << x << ' ' << p << ' ' << dp[x][p] << endl;
			}
		}
		*/
	}
	for (int x = 1; x <= n; x++) {
		int ans = min({dp[x][0], dp[x][1], dp[x][2]});
		printf("%d ", ans);
	}
	cout << endl;
}