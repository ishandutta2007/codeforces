#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef int_fast64_t ll;

void start() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() {
	start();

	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, ll>>> a(n);
	for (int i = 0; i < m; ++i) {
		int v, u;
		ll cost;
		cin >> v >> u >> cost;
		--v;
		--u;
		cost *= 2;
		a[v].push_back({ u, cost});
		a[u].push_back({ v, cost});
	}
	vector<ll> dist(n);
	set<pair<ll, int>> q;
	for (int i = 0; i < n; ++i) {
		cin >> dist[i];
		q.insert({ dist[i], i });
	}

	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (int i = 0; i < (int)a[v].size(); ++i) {
			int u = a[v][i].first;
			ll cost = a[v][i].second;
			if (dist[u] > cost + dist[v]) {
				q.erase({ dist[u], u });
				dist[u] = cost + dist[v];
				q.insert({dist[u], u});
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << dist[i] << " ";
	}
	return 0;
}