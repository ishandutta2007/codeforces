#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;
typedef long double ld;
typedef long long ll;
constexpr int INF = 1000000000;

struct wEdge {
	int u, v, w;
	wEdge() {}
};

struct MaxFlow {
	vector<vector<int>> adjl, cap, flow;
	vector<int> firstNonDel, dist, par;
	int n, s, t;
	int res(int u, int v) {return cap[u][v] - flow[u][v];}
	void addEdge(int u, int v, int w) {
		if (cap[u][v] == 0 and cap[v][u] == 0) {
			adjl[u].push_back(v);
			adjl[v].push_back(u);
		}
		cap[u][v] += w;
	}
	bool updateDistInfo() {
		fill(dist.begin(), dist.end(), -1);
		dist[s] = 0;
		queue<int> q; q.push(s);
		while (not q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : adjl[cur]) {
				if (res(cur, next) > 0 and dist[next] == -1) {
					dist[next] = dist[cur] + 1;
					q.push(next);
				}
			}
		}
		return (dist[t] != -1);
	}
	bool attFindPathToSink(int u) {
		if (u == t) return true;
		for (int &i = firstNonDel[u]; i < adjl[u].size(); ++i) {
			int v = adjl[u][i];
			if (dist[v] == dist[u] + 1 and res(u, v) > 0 and attFindPathToSink(v)) {
				par[v] = u;
				return true;
			}
		}
		dist[u] = -2020;
		return false;
	}
	bool attemptAugment() {
		fill(par.begin(), par.end(), -1);
		par[s] = -2;
		return attFindPathToSink(s);
	}
	int getMaxFlow() {
		int ans = 0;
		while (updateDistInfo()) {
			fill(firstNonDel.begin(), firstNonDel.end(), 0);
			// printf("HERE\n");
			while (attemptAugment()) {
				int aug = INF;
				for (int c = t; par[c] != -2; c = par[c]) aug = min(aug, res(par[c], c));
				// printf("aug %d\n", aug);
				for (int c = t; par[c] != -2; c = par[c]) flow[par[c]][c] += aug, flow[c][par[c]] -= aug;
				ans += aug;
			}
		}
		return ans;
	}
	MaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
		adjl = vector<vector<int>>(n);
		cap = flow = vector<vector<int>>(n, vector<int>(n));
		firstNonDel = dist = par = cap[0];
	}
};

int main() {
	int n, m, x; scanf("%d %d %d", &n, &m, &x);
	vector<wEdge> eList(m);
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &eList[i].u, &eList[i].v, &eList[i].w);
		--eList[i].u; --eList[i].v;
	}
	ld lo = 1e0;
	ld hi = 1e8;
	while (hi - lo > 1e-10) {
		// printf("%.8lf %.8lf\n", double(lo), double(hi));
		ld mid = (lo + hi) / 2;
		ld bearLoad = mid / x;
		MaxFlow dinic(n, 0, n - 1);
		for (wEdge e : eList) {
			ll maxBearPass = e.w / bearLoad;
			dinic.addEdge(e.u, e.v, min(maxBearPass, (ll)x));
			// printf("edge %d %d %d\n", e.u, e.v, int(min(maxBearPass, (ll)x)));
		}
		if (dinic.getMaxFlow() >= x) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	printf("%.10lf\n", double(lo));
	return 0;
}