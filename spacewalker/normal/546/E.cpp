#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
constexpr int INF = 1000000000;
constexpr int CAPINF = 1000000;

struct MaxFlow {
	vector<vector<int>> adjl, cap, flow;
	vector<int> par;
	int n, s, t;
	int res(int i, int j) {
		return cap[i][j] - flow[i][j];
	}
	void addEdge(int i, int j, int v) {
		if (cap[i][j] == 0 and cap[j][i] == 0) {
			adjl[j].push_back(i);
			adjl[i].push_back(j);
		}
		cap[i][j] += v;
	}
	bool attemptFindPath() {
		fill(par.begin(), par.end(), -1);
		par[s] = -2;
		queue<int> q; q.push(s);
		while (not q.empty()) {
			int cur = q.front(); q.pop();
			for (int next : adjl[cur]) {
				if (res(cur, next) > 0 and par[next] == -1) {
					par[next] = cur;
					q.push(next);
					if (next == t) return true;
				}
			}
		}
		return false;
	}
	int getMaxFlow() {
		int ans = 0;
		while (attemptFindPath()) {
			int aug = INF;
			for (int cur = t; par[cur] != -2; cur = par[cur]) aug = min(aug, res(par[cur], cur));
			for (int cur = t; par[cur] != -2; cur = par[cur]) flow[par[cur]][cur] += aug, flow[cur][par[cur]] -= aug;
			ans += aug;
		}
		return ans;
	}
	int getFlowSent(int i, int j) {
		return max(0, flow[i][j]);
	}
	MaxFlow(int n, int s, int t) : n(n), s(s), t(t) {
		adjl = vector<vector<int>>(n);
		cap = flow = vector<vector<int>>(n, vector<int>(n));
		par = vector<int>(n);
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	int SOURCE = 0, SINK = 2*n + 1;
	vector<int> start(n), goal(n);
	for (int i = 0; i < n; ++i) scanf("%d", &start[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &goal[i]);
	int ssum = 0, gsum = 0;
	for (int i = 0; i < n; ++i) ssum += start[i], gsum += goal[i];
	if (ssum != gsum) {
		printf("NO\n");
		return 0;
	}
	MaxFlow edkarp(2*n + 2, SOURCE, SINK);
	for (int i = 0; i < n; ++i) {
		edkarp.addEdge(SOURCE, i + 1, start[i]);
		edkarp.addEdge(i + 1 + n, SINK, goal[i]);
		edkarp.addEdge(i + 1, i + 1 + n, CAPINF);
	}
	for (int i = 0; i < m; ++i) {
		int p, q; scanf("%d %d", &p, &q);
		edkarp.addEdge(p, q + n, CAPINF);
		edkarp.addEdge(q, p + n, CAPINF);
	}
	int fVal = edkarp.getMaxFlow();
	// printf("MAX FLOW %d\n", fVal);
	if (fVal != ssum) {
		printf("NO\n");
	} else {
		printf("YES\n");
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				printf("%s%d", (j == 0 ? "" : " "), edkarp.getFlowSent(i + 1, j + n + 1));
			}
			printf("\n");
		}
	}
	return 0;
}