#include <bits/stdc++.h>
#define ll long long
#define maxn 505 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vector<pi> ls[2][maxn][maxn];
ll dp[maxn][maxn][2];
ll w[maxn][maxn];
int main() {
	int mv[4][2] = {{1, -1}, {0, 1}, {-1, 1}, {0, -1}};
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		int x, y, d, t, e;
		scanf("%d%d%d%d%d", &x, &y, &d, &t, &e);
	//	if ((x + y - t) % 2) continue;
		vector<pi> cur;
		if ((x + y - t) % 4 == 0 && x + y >= t) cur.pb(mp(x, y));
		t++, x += d, y -= d;
		if ((x + y - t) % 4 == 0 && x + y >= t) cur.pb(mp(x, y));
		t++, y += d;
		if ((x + y - t) % 4 == 0 && x + y >= t) cur.pb(mp(x, y));
		t++, x -= d, y += d;
		if ((x + y - t) % 4 == 0 && x + y >= t) cur.pb(mp(x, y));
		sort(cur.begin(), cur.end());
		for (int j = 0; j < cur.size(); j++) {
			if (j == 0) {
				w[cur[j].fi][cur[j].se] += e;
				continue;
			}
			for (int k = 0; k < 2; k++) {
				int cpl = -1;
				if (k && cur[j - 1].fi == cur[j].fi) cpl = cur[j - 1].se;
				if (k == 0 && cur[j - 1].se == cur[j].se) cpl = cur[j - 1].fi;
				ls[k][cur[j].fi][cur[j].se].pb(mp(cpl, e));
			}
		}
	//	for (auto v : cur) cout << v.fi << ' ' << v.se << endl;
	}
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--) {
			for (int k = 0; k < 2; k++) {
			//	for (auto v : ls[k][i][j])
			//		cout << i << ' ' << j << ' ' << k << ' ' << v.fi << ' ' << v.se << endl;
				if (i == n - 1 && j == m - 1) dp[i][j][k] = 0;
				else {
					if (k == 0) {
						dp[i][j][k] = 1e18;
						ll pl = 0;
						for (int q = i + 1; q <= n - 1; q++) {
							pl += w[q][j];
							for (auto v : ls[k][q][j])
								if (v.fi < i) pl += v.se;
							dp[i][j][k] = min(dp[i][j][k], dp[q][j][k ^ 1] + pl);
						}
					}
					else {
						dp[i][j][k] = 1e18;
						ll pl = 0;
						for (int q = j + 1; q <= m - 1; q++) {
							pl += w[i][q];
							for (auto v : ls[k][i][q])
								if (v.fi < j) pl += v.se;
							dp[i][j][k] = min(dp[i][j][k], dp[i][q][k ^ 1] + pl);
						}
					} 
				}
			}
		}
	cout << min(dp[0][0][0], dp[0][0][1]);
	return 0;
}