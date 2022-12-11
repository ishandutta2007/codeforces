// Codeforces - mycopka

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef int64_t ll;

const ll INF = (ll)(1e18) + 666;

ll n, m;
vector<vector<ll>> g;
vector<vector<ll>> rg;

vector<ll> bfs(ll v) {
	vector<ll> dist(n, INF);
	dist[v] = 0;
	queue<ll> q;
	q.push(v);
	while (!q.empty()) {
		ll v = q.front();
		q.pop();
		for (ll u : rg[v]) {
			if (dist[u] == INF) {
				dist[u] = dist[v] + 1;
				q.push(u);
			}
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin.tie(nullptr);

	cin >> n >> m;
	g.resize(n);
	rg.resize(n);
	for (ll i = 0; i < m; ++i) {
		ll v, u;
		cin >> v >> u;
		g[v - 1].emplace_back(u - 1);
		rg[u - 1].emplace_back(v - 1);
	}
	ll k;
	cin >> k;
	vector<ll> path(k);
	for (ll i = 0; i < k; ++i) {
		cin >> path[i];
		--path[i];
	}
	vector<ll> dist = bfs(path.back());
	ll cnt_min = 0;
	ll cnt_max = 0;
	for (ll i = 0; i < k - 1; ++i) {
		ll v = path[i];
		ll next = path[i + 1];
		bool flag = false;
		for (ll u : g[v]) {
			if (u == next) {
				continue;
			}
			if (dist[u] == dist[v] - 1) {
				flag = true;
			}
		}
		if (flag) {
			++cnt_max;
			if (dist[next] != dist[v] - 1) {
				++cnt_min;
			}
		}
	}
	cout << cnt_min << " " << cnt_max << endl;
	return 0;
}