#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr ll INF = 1000000000000000000;

vector<vector<int>> spDag;
vector<int> toposort;
vector<bool> marked;

void makeToposort(int v) {
	if (marked[v]) return;
	marked[v] = true;
	for (int nxt : spDag[v]) makeToposort(nxt);
	toposort.push_back(v);
}

vector<int> madadamay;
vector<int> indeg, frozenDeg;
vector<int> victims;

void attemptAssassination(int v, int root) {
//	printf("killing %d under %d\n", v, root);
	++madadamay[root];
	marked[v] = true;
	for (int nxt : spDag[v]) {
		--indeg[nxt];
		victims.push_back(nxt);
//		printf("next %d now has indeg %d\n", nxt, indeg[nxt]);
		if (indeg[nxt] == 0) {
			attemptAssassination(nxt, root);
		}
	}
}


int main() {
	int n, m, s; scanf("%d %d %d", &n, &m, &s); --s;
	vector<vector<pair<int, ll>>> graph(n);
	for (int i = 0; i < m; ++i) {
		int u, v; ll w; scanf("%d %d %lld", &u, &v, &w);
		graph[--u].emplace_back(--v, w);
		graph[v].emplace_back(u, w);
	}
	vector<ll> dist(n, INF);
	dist[s] = 0;
	set<pair<ll, int>> toVisit;
	for (int i = 0; i < n; ++i) toVisit.emplace(dist[i], i);
	while (!toVisit.empty()) {
		ll dtc; int cur;
		tie(dtc, cur) = *toVisit.begin(), toVisit.erase(toVisit.begin());
		if (dtc == INF) continue;
		for (auto n_w : graph[cur]) {
			if (n_w.second + dtc < dist[n_w.first]) {
				toVisit.erase(make_pair(dist[n_w.first], n_w.first));
				toVisit.emplace(dist[n_w.first] = n_w.second + dtc, n_w.first);
			}
		}
	}
//	for (int i = 0; i < n; ++i) printf("%d dist %lld\n", i, dist[i]);
	spDag = vector<vector<int>>(n);
	for (int i = 0; i < n; ++i) {
		for (auto n_w : graph[i]) {
			if (dist[i] + n_w.second == dist[n_w.first]) spDag[i].push_back(n_w.first);
		}
	}
	marked = vector<bool>(n);
	makeToposort(s);
	reverse(begin(toposort), end(toposort));
	madadamay = frozenDeg = indeg = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		for (int nxt : spDag[i]) {
			++frozenDeg[nxt];
//			printf("dag edge %d %d\n", i, nxt);		
		}
	}
	indeg = frozenDeg;
	marked.assign(n, false);
	for (int v : toposort) {
		if (!marked[v] && v != s) {
			attemptAssassination(v, v);
			for (int x : victims) indeg[x] = frozenDeg[x];
			victims.clear();
		}
	}
	printf("%d\n", *max_element(begin(madadamay), end(madadamay)));
	return 0;
}