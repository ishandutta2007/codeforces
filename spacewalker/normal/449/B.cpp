#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
#include <algorithm>
#include <utility>
#define ROOT 0
#define INF 1000000000000000000

using namespace std;
typedef long long ll;

int main() {
	int n, m, k; scanf("%d %d %d", &n, &m, &k);
	vector<vector<pair<int, ll>>> graph(n, vector<pair<int, ll>>());
	for (int i = 0; i < m; ++i) {
		int u, v; ll x; scanf("%d %d %lld", &u, &v, &x);
		graph[--u].emplace_back(--v, x);
		graph[v].emplace_back(u, x);
	}
	vector<pair<int, ll>> directRoads;
	directRoads.reserve(k);
	for (int i = 0; i < k; ++i) {
		int s; ll y; scanf("%d %lld", &s, &y);
		directRoads.emplace_back(--s, y);
		graph[ROOT].emplace_back(s, -y);
	}
	vector<ll> dist(n, INF);
	vector<bool> visited(n, false);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
	dist[ROOT] = 0;
	pq.emplace(0, ROOT);
	while (!pq.empty()) {
		auto dist_v = pq.top(); pq.pop();
		if (visited[dist_v.second]) {
			continue;
		}
		visited[dist_v.second] = true;
		for (auto next_d : graph[dist_v.second]) {
			ll realW = abs(next_d.second);
			if (!visited[next_d.first] && dist_v.first + realW < dist[next_d.first]) {
				dist[next_d.first] = dist_v.first + realW;
				pq.emplace(dist[next_d.first], next_d.first);
			}
		}
	}
	vector<bool> spNonTrainExists(n, false);
	for (int i = 0; i < n; ++i) {
		//printf("dist %d is %lld\n", i, dist[i]);
		for (auto neigh_d : graph[i]) {
			if (neigh_d.second > 0 && dist[neigh_d.first] + neigh_d.second == dist[i]) {
				spNonTrainExists[i] = true;
				//printf("found non-train edge for %d\n", i);
			}
		}
	}
	int ans = 0;
	vector<bool> trainNecessary(n, false);
	for (auto dest_w : directRoads) {
		if ((dest_w.second == dist[dest_w.first] && 
			!spNonTrainExists[dest_w.first])) {
			trainNecessary[dest_w.first] = true;
			//printf("%d needs a train road\n", dest_w.first);
		}
	}
	ans = k - count(trainNecessary.begin(), trainNecessary.end(), true);
	printf("%d\n", ans);
	return 0;
}