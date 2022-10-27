#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	int t; 
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;
		int a[n];
		for (int i = 0; i < n; i ++)
			cin >> a[i];

		vector<pair<int,int> > segs[n+1];
		sort(a, a + n);
		for (int i = 0; i < m; i ++) {
			int l, r;
			cin >> l >> r;
			int p = lower_bound(a, a + n, l) - a;
			if (p < n && a[p] <= r) continue;
			segs[p].emplace_back(l, r);
		}

		for (int i = 0; i <= n; i ++) {
			sort(segs[i].begin(), segs[i].end());
			vector< pair<int,int> > tmp;
			for (auto [l, r]: segs[i]) {
				if (!tmp.empty() && l == tmp.back().first) 
					continue;
				
				while (!tmp.empty() && tmp.back().second >= r) 
					tmp.pop_back();
				
				tmp.emplace_back(l, r);
			}
			segs[i] = tmp;
		}
		
		for (int i = 0; i < n; i ++) {
			segs[i].emplace_back(a[i], a[i]);
			segs[i+1].insert(segs[i+1].begin(), make_pair(a[i], a[i]));
		}

		ll dp[2] = {};
		dp[0] = a[0] - segs[0][0].second;
		dp[1] = 2 * dp[0];
		
		auto upd = [](ll &x, ll y) {
			x = min(x, y);
		};

		for (int i = 1; i < n; i ++) {
			ll f[2] = {inf, inf};
			for (int j = 1; j < segs[i].size(); j ++) {
				upd(f[0], 1ll * (a[i] - segs[i][j].second) + dp[0] + 2ll * (segs[i][j-1].first - a[i-1]));
				upd(f[0], 1ll * (a[i] - segs[i][j].second) + dp[1] + 1ll * (segs[i][j-1].first - a[i-1]));
				upd(f[1], 2ll * (a[i] - segs[i][j].second) + dp[0] + 2ll * (segs[i][j-1].first - a[i-1]));
				upd(f[1], 2ll * (a[i] - segs[i][j].second) + dp[1] + 1ll * (segs[i][j-1].first - a[i-1]));
			} 
			dp[0] = f[0], dp[1] = f[1];
		}
		ll ans = inf;
		upd(ans, 1ll * (segs[n].back().first - a[n-1]) + dp[1]);
		upd(ans, 2ll * (segs[n].back().first - a[n-1]) + dp[0]);
		cout << ans << "\n";
	}
}