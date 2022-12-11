#include <bits/stdc++.h>

using namespace std;

char curSched[100];
forward_list<int> graph[100000], revGraph[100000];
forward_list<int> sccDag[5000000];
vector<int> sccID;
vector<pair<int, int>> visitOrder;
vector<int> bukasNaMuseoSaSCC;
vector<int> sagotDito;

int n, m, d;

int flatten(int i, int t) {
	return n * t + i;
}

void buildVisitOrder(int i, int t) {
	if (sccID[flatten(i, t)] != -1) return;
	sccID[flatten(i, t)] = 1;
	for (int nxt : graph[i]) buildVisitOrder(nxt, (t + 1) % d);
	visitOrder.emplace_back(i, t);
}

void computeSCCIDs(int i, int curComp, int t) {
	int u = flatten(i, t);
	if (sccID[u] != -1) return;
	sccID[u] = curComp;
	for (int nxt : revGraph[i]) computeSCCIDs(nxt, curComp, (t + d - 1) % d);
}

int findAnswer(int scc) {
	if (sagotDito[scc] != -1) return sagotDito[scc];
	int ans = 0;
	for (int nxt : sccDag[scc]) ans = max(ans, findAnswer(nxt));
	return sagotDito[scc] = ans + bukasNaMuseoSaSCC[scc];
}

int main() {
	scanf("%d %d %d", &n, &m, &d);
	for (int i = 0; i < m; ++i) {
		int u, v; 
		scanf("%d %d", &u, &v);
		graph[--u].push_front(--v);
		revGraph[v].push_front(u);
	}
	sccID = vector<int>(n * d, -1);
	bukasNaMuseoSaSCC = vector<int>(n * d, 0);
	visitOrder.reserve(n * d);
	for (int i = 0; i < n; ++i) {
		for (int t = 0; t < d; ++t) {
			buildVisitOrder(i, t);
		}
	}
	sccID.assign(n * d, -1);
	reverse(begin(visitOrder), end(visitOrder));
	for (auto i_t : visitOrder) {
		int i, t; tie(i, t) = i_t;
		computeSCCIDs(i, flatten(i, t), t); 
	}
	for (int i = 0; i < n; ++i) {
		set<int> openInSCC;
		scanf("%s", curSched);	
		for (int t = 0; t < d; ++t) {
			if (curSched[t] == '1') openInSCC.insert(sccID[flatten(i, t)]);
		}
		for (int s : openInSCC) ++bukasNaMuseoSaSCC[s];
	}
	for (int i = 0; i < n; ++i) {
		for (int j : graph[i]) {
			for (int t = 0; t < d; ++t) {
				int u = flatten(i, t), v = flatten(j, (t + 1) % d);
				if (sccID[u] != sccID[v]) {
					sccDag[sccID[u]].push_front(sccID[v]);
				}
			}
		}
	}
	sagotDito = vector<int>(n * d, -1);
	printf("%d\n", findAnswer(sccID[flatten(0, 0)]));
	return 0;
}