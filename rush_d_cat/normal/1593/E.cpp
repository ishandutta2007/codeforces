#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 400000 + 10;
vector<int> g[N];

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	int t;
	cin >> t;
	while (t --) {
		int n, k;
		cin >> n >> k;
		for (int i = 1; i <= n; i ++)
			g[i].clear();

		for (int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		queue<int> q;
		vector<int> deg(n + 1, 0), d(n + 1, 0);
		for (int i = 1; i <= n; i ++) {
			deg[i] = g[i].size();
			if (deg[i] <= 1)
				q.push(i);
		}

		while (q.size()) {
			vector<int> tmp;
			while (q.size()) {
				int u = q.front(); q.pop();
				for (auto v: g[u]) {
					if (deg[v] >= 2) {
						deg[v] --;
						if (deg[v] <= 1) {
							tmp.emplace_back(v);
							//printf("v = %d\n", v);
							d[v] = d[u] + 1;
						}
					}
				}
			}
			for (auto x: tmp) q.push(x);
		}
		int ans = 0;
		for (int i = 1; i <= n; i ++) if (d[i] >= k) ans ++;
		cout << ans << "\n";
	}
}