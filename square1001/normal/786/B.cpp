#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 62;
struct edge {
	int to; long long cost;
};
struct state {
	int pos; long long cost;
};
bool operator<(const state& s1, const state& s2) {
	return s1.cost > s2.cost;
}
int main() {
	int N, Q, S;
	cin >> N >> Q >> S; --S;
	int sz = 1;
	while (sz < N) sz *= 2;
	vector<vector<edge> > G(3 * sz);
	for (int i = 2; i < 2 * sz; ++i) {
		G[i / 2].push_back(edge{ i, 0 });
		G[(i < sz ? 2 * sz : 0) + i].push_back(edge{ 2 * sz + i / 2, 0 });
	}
	for (int i = 0; i < Q; ++i) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			int v, u, w;
			cin >> v >> u >> w; --v, --u;
			G[sz + v].push_back(edge{ sz + u, w });
		}
		if (tp == 2) {
			int v, l, r, w;
			cin >> v >> l >> r >> w; --v, --l;
			l += sz, r += sz;
			while (l != r) {
				if (l & 1) G[sz + v].push_back(edge{ l, w }), ++l;
				if (r & 1) --r, G[sz + v].push_back(edge{ r, w });
				l >>= 1, r >>= 1;
			}
		}
		if (tp == 3) {
			int v, l, r, w;
			cin >> v >> l >> r >> w; --v, --l;
			l += sz; r += sz;
			while (l != r) {
				if (l & 1) G[(l < sz ? 2 * sz : 0) + l].push_back(edge{ sz + v, w }), ++l;
				if (r & 1) --r, G[(r < sz ? 2 * sz : 0) + r].push_back(edge{ sz + v, w });
				l >>= 1, r >>= 1;
			}
		}
	}
	vector<long long> dist(3 * sz, inf);
	priority_queue<state> que;
	dist[sz + S] = 0;
	que.push(state{ sz + S, 0 });
	while (!que.empty()) {
		int u = que.top().pos; que.pop();
		for (edge e : G[u]) {
			if (dist[e.to] > dist[u] + e.cost) {
				dist[e.to] = dist[u] + e.cost;
				que.push(state{ e.to, dist[e.to] });
			}
		}
	}
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		cout << (dist[sz + i] != inf ? dist[sz + i] : -1);
	}
	cout << '\n';
	return 0;
}