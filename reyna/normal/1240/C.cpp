
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define mp make_pair
#define x first
#define y second
#define pb push_back
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
#define int long long
const int N = (int) 1e6 + 6, mod = (int) 0;
int k;
int dp[N][2];
vector<pair<int, int>> adj[N];
void dfs(int v, int p = -1) {
	dp[v][0] = dp[v][1] = 0;
	vector<pair<int, pair<int, int>>> all;
	int res = 0;
	for (auto e : adj[v]) if (e.first != p) {
		int u = e.first, w = e.second;
		dfs(u, v);
		res += dp[u][1];
		all.push_back(mp(dp[u][0] + w - (dp[u][1]), mp(u, w)));
	}
	sort(ALL(all));
	reverse(ALL(all));
	for (int use = k - 1; use <= k; ++use) {
		int act_use = min(use, (int) all.size());
		int cur_res = 0;
		int t_res = res;
		for (int j = 0; j < act_use; ++j) if (all[j].first >= 0) {
			int u = all[j].second.first, w = all[j].second.second;
			t_res -= dp[u][1];
			cur_res += dp[u][0] + w;
		}
		dp[v][use - (k - 1)] = max(dp[v][use - (k - 1)], cur_res + t_res);
	}
	dp[v][1] = max(dp[v][1], dp[v][0]);
	
}
int32_t main() {
	ios_base::sync_with_stdio(0);
	memset(dp, -63, sizeof dp);
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n >> k;
		for (int j = 0; j < n - 1; ++j) {
			int u, v, w;
			cin >> u >> v >> w;
			--u, --v;
			adj[u].pb(mp(v, w));
			adj[v].pb(mp(u, w));
		}
		dfs(0);
		cout << max(dp[0][0], dp[0][1]) << '\n';
		for (int j = 0; j < n; ++j) adj[j].clear(), dp[j][0] = dp[j][1] = -1e9;
	}
}