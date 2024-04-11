#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
bitset<200008> used;
vector<vector<int>> graph, graph2;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	graph.resize(n); graph2.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		graph[v].pb(u);
		graph2[u].pb(v);
	}
	int k; cin >> k;
	vector<int> P(k);
	for (int i = 0; i < k; i++) {cin >> P[i]; P[i]--;}
	int s = P[0], t = P.back();
	deque<pair<int, int>> q = {{t, 0}};
	used[t] = true;
	vector<int> depth(n);
	depth[t] = 0;
	while (!q.empty()) {
		int p = q.front().first, dep = q.front().second;
		q.pop_front();
		for (auto u : graph[p]) {
			if (!used[u]) {
				q.pb({u, dep + 1});
				depth[u] = dep + 1;
				used[u] = true;
			}
		}
	}
	int ans1 = 0, ans2 = 0;
	vector<bool> kek(k + 2, true);
	for (int i = 0; i < k - 1; i++) {
		vector<int> sons;
		for (auto p : graph2[P[i]]) {
			sons.pb(depth[p]);
		}
		sort(sons.begin(), sons.end());
		if (sons.size() > 1 && sons[0] == sons[1]) {
			ans2++;
			kek[i] = false;
		}
	}
	for (int i = 0; i < k - 1; i++) {
	    int mim = 1e9;
	    for (auto u : graph2[P[i]]) {
	        mim = min(mim, depth[u]);
	    }
	    if (mim != depth[P[i + 1]]) {
	        ans1++;
	        if (kek[i]) ans2++;
	    }
	}
	cout << ans1 << ' ' << ans2;
}