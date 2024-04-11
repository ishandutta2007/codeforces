#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

vector<int> weight, mouseto, inCycle;
vector<vector<int>> mtGraph;

vector<bool> vis, cycleVis, clearVis;

int findCycleElem(int v) {
	if (vis[v]) return v;
	else {
		vis[v] = true;
		return findCycleElem(mouseto[v]);
	}
}

void fillCycleElem(int v) {
	if (cycleVis[v]) return;
	else {
		inCycle.push_back(weight[v]);
		cycleVis[v] = true;
		fillCycleElem(mouseto[v]);
	}
} 

void markCompVisited(int v) {
	// printf("marking %d visited\n", v);
	clearVis[v] = true;
	vis[v] = true;
	cycleVis[v] = true;
	for (int next : mtGraph[v]) {
		// printf("next is %d\n", next);
		if (!clearVis[next]) {
			markCompVisited(next);
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	weight = mouseto = vector<int>(n);
	mtGraph = vector<vector<int>>(n);
	vis = cycleVis = clearVis = vector<bool>(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &weight[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &mouseto[i]);
		--mouseto[i];
		mtGraph[i].push_back(mouseto[i]);
		mtGraph[mouseto[i]].push_back(i);
		// printf("edge %d %d\n", i, mouseto[i]);
	}
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		if (!clearVis[i]) {
			int vcRoot = findCycleElem(i);
			// printf("%d in cycle\n", vcRoot);
			fillCycleElem(vcRoot);
			ans += *min_element(inCycle.begin(), inCycle.end());
			markCompVisited(i);
			inCycle.clear();
		}
	}
	printf("%lld\n", ans);
	return 0;
}