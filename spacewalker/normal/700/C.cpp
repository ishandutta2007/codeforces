#include <bits/stdc++.h>

using namespace std;

constexpr int INF = 2100000000;

vector<int> vParent;
vector<bool> isBridge;
vector<vector<pair<int, int>>> cgraph;
vector<int> low, disc;
vector<pair<int, int>> elist;
int cdTime;
int s, t;
int n, m; 

void calculateParents(int v, int p) {
	int edgesToParent = 0;
	low[v] = disc[v] = cdTime;
	cdTime++;
	for (auto n_l : cgraph[v]) {
		if (n_l.first == p) {
			++edgesToParent;
			continue;
		}
		if (vParent[n_l.first] == -1) {
			vParent[n_l.first] = n_l.second;
			calculateParents(n_l.first, v);
			low[v] = min(low[v], low[n_l.first]);
		} else {
			low[v] = min(low[v], disc[n_l.first]);
		}
	}
//	printf("%d etp %d low %d disc %d\n", v, edgesToParent, low[v], disc[v]);
	if (p != -1 && edgesToParent == 1 && low[v] == disc[v]) isBridge[vParent[v]] = true;
}

void resetGlobals() {
	vParent = vector<int>(n, -1);
	isBridge = vector<bool>(m, false);
	cdTime = 0;
	low = disc = vector<int>(n, -1);
	vParent[s] = -2;
}

void listEdgesToSource(int v, vector<int> &e) {
	if (v == s) return;
	int etp = vParent[v];
	e.push_back(etp);
	listEdgesToSource(elist[etp].first + elist[etp].second - v, e);
}


int main() {
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s, &t); --s; --t;
	vector<vector<pair<int, int>>> origGraph(n);
	vector<int> edgeWeights(m);
	for (int i = 0; i < m; ++i) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		origGraph[--u].emplace_back(--v, i);
		origGraph[v].emplace_back(u, i);
		edgeWeights[i] = w;
		elist.emplace_back(u, v);
	}
	resetGlobals();
	cgraph = origGraph;
	calculateParents(s, -1);
	if (vParent[t] == -1) {
		printf("0\n0\n\n");
		return 0;
	}
	vector<int> eToRemove; listEdgesToSource(t, eToRemove);
	vector<int> ans{1, 2, 3};
	int cValAns = INF;
	for (int e : eToRemove) {
		cgraph = vector<vector<pair<int, int>>>(n);
		for (int i = 0; i < n; ++i) {
			for (auto n_l : origGraph[i]) {
				if (n_l.second == e) continue;
//				printf("copying edge %d->%d (%d)\n", i, n_l.first, n_l.second);
				cgraph[i].push_back(n_l);
			}
		}
//		printf("attempting %d removal\n", e);
		resetGlobals();
		calculateParents(s, -1);
		if (vParent[t] == -1) {
			if (cValAns > edgeWeights[e]) {
				ans = vector<int>{e};
				cValAns = edgeWeights[e];
			}
			continue;
		} else {
			vector<int> eTest; listEdgesToSource(t, eTest);
			for (int i : eTest) {
				if (i == e) continue;
//				printf("%d on remaining s-t path\n", i);
//				if (isBridge[i]) printf("%d bridge if %d removed\n", i, e);
				if (isBridge[i] && cValAns > edgeWeights[e] + edgeWeights[i]) {
					ans = vector<int>{e, i};
					cValAns = edgeWeights[e] + edgeWeights[i];
				}
			}
		}
	}
	if (cValAns == INF) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", cValAns);
	printf("%lu\n", ans.size());
	for (int x : ans) printf("%d ", x + 1);
	printf("\n");
	return 0;
}