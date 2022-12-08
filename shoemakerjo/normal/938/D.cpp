#include <bits/stdc++.h>

using namespace std;
#define maxn 200010
#define ll long long
#define pli pair<ll, int>
#define pil pair<int, ll>

vector<vector<pil>> adj(maxn);
ll cost[maxn];



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	int u, v;
	ll w;
	while (m--) {
		cin >> u >> v >> w;
		adj[u].push_back(pil(v, w));
		adj[v].push_back(pil(u, w));
	}
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
		pq.push(pli(cost[i], i));
	}
	while (pq.size() > 0) {
		pli cur = pq.top(); pq.pop();
		ll co = cur.first;
		u = cur.second;
		if (co > cost[u]) continue;
		for (int i = 0; i < adj[u].size(); i++) {
			v = adj[u][i].first;
			w = adj[u][i].second;
			if (cost[v] > 2*w + cost[u]) {
				cost[v] = 2*w + cost[u];
				pq.push(pli(cost[v], v));
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << cost[i] << " ";
	}
	cout << endl;
	cin >> n;

}