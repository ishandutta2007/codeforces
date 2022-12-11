#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<ll, pair<int, int>> edge;

class unionfind {
	vector<int> rank;
	vector<int> par;
	int n;
public:
	unionfind(int ct) : rank(ct, 0), par(ct, 0), n(ct) {
		for (int i = 0; i < n; ++i) {
			par[i] = i;
		}
	}
	int find(int x) {
		if (par[x] == x) {
			return x;
		} else {
			return (par[x] = find(par[x]));
		}
	}
	void join(int x, int y) {
		int xr = find(x);
		int yr = find(y);
		if (xr != yr) {
			if (rank[xr] >= rank[yr]) {
				if (rank[xr] == rank[yr]) {
					++rank[xr];
				}
				par[yr] = xr;
			} else {
				par[xr] = yr;
			}
		}
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<edge> edges;
	vector<vector<ll>> graph(n, vector<ll>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%lld", &graph[i][j]);
			edges.emplace_back(graph[i][j], make_pair(i, j));
		}
	}
	bool passPrelims = true;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[i][j] != graph[j][i] || (graph[i][j] == 0 && i != j)) {
				passPrelims = false;
			}
		}
	}
	if (!passPrelims) {
		printf("NO\n");
		return 0;
	}
	sort(edges.begin(), edges.end());
	vector<vector<int>> tree(n, vector<int>());
	unionfind ace(n);
	for (edge w_i_j : edges) {
		int i, j; i = w_i_j.second.first; j = w_i_j.second.second;
		if (ace.find(i) != ace.find(j)) {
			ace.join(i, j);
			tree[i].push_back(j);
			tree[j].push_back(i);
			//printf("picking edge %d %d\n", i, j);
		}
	}
	vector<vector<ll>> sdist(n, vector<ll>(n, -1));
	for (int start = 0; start < n; ++start) {
		queue<int> q;
		sdist[start][start] = 0;
		q.push(start);
		while (!q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : tree[cur]) {
				if (sdist[start][next] == -1) {
					sdist[start][next] = sdist[start][cur] + graph[cur][next];
					q.push(next);
				}
			}
		}
	}
	printf("%s\n", (sdist == graph ? "YES" : "NO"));
	return 0;
}