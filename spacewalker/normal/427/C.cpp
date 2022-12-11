#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stack>
#define MOD 1000000007

using namespace std;
typedef long long ll;

stack<int> toVisit;
vector<int> cptidx;

void DFS(const vector<vector<int>> &graph, int cur) {
	cptidx[cur] = -1;
	for (int next : graph[cur]) {
		if (cptidx[next] == -10) {
			DFS(graph, next);
		}
	}
	toVisit.push(cur);
}

void assignCC(const vector<vector<int>> &rev, int cur, int toAssign) {
	cptidx[cur] = toAssign;
	for (int next : rev[cur]) {
		if (cptidx[next] == -1) {
			assignCC(rev, next, toAssign);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m; cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	vector<vector<int>> rev(n, vector<int>());
	vector<ll> costs(n, 0);
	for (int i = 0; i < n; ++i) {
		cin >> costs[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v;
		graph[--v].push_back(--u);
		rev[u].push_back(v);
	}
	cptidx = vector<int>(n, -10); // to be set to -1 when visited
	for (int i = 0; i < n; ++i) {
		if (cptidx[i] == -10) {
			DFS(graph, i);
		}
	}
	//cout << "thing finished" << endl;
	while (!toVisit.empty()) {
		int cur = toVisit.top(); toVisit.pop();
		if (cptidx[cur] == -1) {
			assignCC(rev, cur, cur);
		}
	}
	vector<vector<int>> costsByGroup(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		costsByGroup[cptidx[i]].push_back(costs[i]);
	}
	ll minCost = 0;
	ll waysForMin = 1;
	for (vector<int> grp : costsByGroup) {
		if (!grp.empty()) {
			int mine = *min_element(grp.begin(), grp.end());
			minCost += mine;
			waysForMin = (waysForMin * count(grp.begin(), grp.end(), mine)) % MOD;
		}
	}
	cout << minCost << " " << waysForMin << endl;
	return 0;
}