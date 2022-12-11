#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 1000000000;

struct MaxFlowFinder {
	vector<vector<pair<int, int>>> graph;
	vector<pair<int, int>> elist;
	vector<int> cap, flow, eToExtend;
	vector<int> eToPar;
	int n, s, t;
	int curStretch, curMaxFlow;
	MaxFlowFinder(int n, int s, int t, int maxEdges) : graph(n), eToPar(n), n(n), s(s), t(t), 
		curStretch(0), curMaxFlow(0) {
		flow.reserve(2*maxEdges);
		cap.reserve(2*maxEdges);
	}
	int residual(int e) {
		return cap[e] - flow[e];
	}
	void addEdge(int u, int v, int c, bool extendo) {
		int ita = elist.size();
		if (extendo) eToExtend.push_back(ita);
		graph[u].emplace_back(v, ita);
		graph[v].emplace_back(u, ita + 1);
		cap.push_back(c);
		cap.push_back(0);
		flow.push_back(0);
		flow.push_back(0);
		elist.emplace_back(u, v);
		elist.emplace_back(v, u);
	}
	void stretchEdges() {
		++curStretch;
		for (int e : eToExtend) ++cap[e];
	}
	bool findAugPath() {
		fill(begin(eToPar), end(eToPar), -1);
		stack<int> q;
		q.push(s);
		eToPar[s] = -2;
		while (!q.empty()) {
			int cur = q.top(); q.pop();
			if (cur == t) return true;
			for (auto v_e : graph[cur]) {
				if (residual(v_e.second) > 0 && eToPar[v_e.first] == -1) {
					eToPar[v_e.first] = v_e.second;
					if (v_e.first == t) return true;
//					printf("etp %d %d\n", v_e.first, v_e.second);
//					printf("that edge is %d %d\n", elist[v_e.second].first, elist[v_e.second].second);
					q.push(v_e.first);
				}
			}
		}
		return false;
	}
	int updateMaxFlow() {
		while (findAugPath()) {
//			printf("ans %d find path\n", ans);
			int minCap = INF;
			for (int cv = t; eToPar[cv] != -2; cv = elist[eToPar[cv]].first) {
				minCap = min(minCap, residual(eToPar[cv]));
			}
			for (int cv = t; eToPar[cv] != -2; cv = elist[eToPar[cv]].first) {
				flow[eToPar[cv]] += minCap;
				flow[eToPar[cv] ^ 1] -= minCap;
			}
			curMaxFlow += minCap;
		}
		return curMaxFlow;
	}
};

int main() {
	int n, m; scanf("%d %d", &n, &m);
	vector<pair<int, int>> elist(m);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v); --u; --v;
		elist[i] = make_pair(u, v);
	}
	MaxFlowFinder veerus(n + m + 2, 0, n + m + 1, 3 * m + n);
	for (int i = 0; i < n; ++i) veerus.addEdge(m + 1 + i, m + n + 1, 0, true);
	for (int i = 0; i < m; ++i) {
		veerus.addEdge(0, i + 1, 1, false);
		veerus.addEdge(i + 1, m + 1 + elist[i].first, 1, false);
		veerus.addEdge(i + 1, m + 1 + elist[i].second, 1, false);
	}
	while (veerus.updateMaxFlow() < m) veerus.stretchEdges();
	printf("%d\n", veerus.curStretch);
	for (int i = 0; i < veerus.elist.size(); ++i) {
		auto ce = veerus.elist[i];
		if (1 <= ce.first && ce.first <= m && m + 1 <= ce.second && ce.second <= m + n
				&& veerus.residual(i) == 0) {
			int corEdge = ce.first - 1, unluckyDude = ce.second - m - 1;
			int luckyDude = elist[corEdge].first ^ elist[corEdge].second ^ unluckyDude;
			printf("%d %d\n", unluckyDude + 1, luckyDude + 1);
		}
	}
	return 0;
}