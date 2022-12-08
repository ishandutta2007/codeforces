#include <bits/stdc++.h>

using namespace std;

#define maxn 1005
vector<vector<int>> adj(maxn);
int dists[maxn], distt[maxn];
bool dtk[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	set<int> rod; //store roads as min*2000 + max
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill(dists, dists+maxn, n*3);
	fill(distt, distt+maxn, n*3);
	dists[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (auto nx : adj[u]) {
			if (dists[nx] > dists[u]+1) {
				dists[nx] = dists[u]+1;
				q.push(nx);
			}
		}
	}
	distt[t] = 0;
	q.push(t);
	while (!q.empty()) {
		u = q.front(); q.pop();
		for (auto nx : adj[u]) {
			if (distt[nx] > distt[u]+1) {
				distt[nx] = distt[u]+1;
				q.push(nx);
			}
		}
	}
	int ans = 0;
	int gd = distt[s];
	fill(dtk, dtk+maxn, false);
	assert(distt[s] == dists[t]);
	for (int i = 1; i <= n; i++) {
		for (auto nx : adj[i]) {
			dtk[nx] = true;
		}
		for (int j = i+1; j <= n; j++) {
			if (dtk[j]) continue;
			if (dists[i] + distt[j] + 1 < gd || 
				distt[i]+dists[j]+1 < gd) continue;
			ans++;
		}
		for (auto nx : adj[i]) {
			dtk[nx] = false;
		}
	}
	cout << ans << endl;
	cin >> n;
}