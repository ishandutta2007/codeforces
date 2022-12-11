#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<vector<int>> graph(n, vector<int>());
	vector<int> orig(n, 0);
	for (int i = 0; i < n; ++i) {
		int fi; scanf("%d", &fi);
		graph[--fi].push_back(i);
		graph[i].push_back(fi);
		orig[i] = fi;
	}
	//
	vector<int> comps(n, -1);
	vector<vector<int>> byComp;
	int ccomp = 0;
	for (int i = 0; i < n; ++i) {
		if (comps[i] == -1) {
			comps[i] = ccomp++;
			queue<int> q;
			vector<int> clist;
			q.push(i);
			while (!q.empty()) {
				int cur = q.front(); q.pop();
				clist.push_back(cur);
				//printf("%d in component %d\n", cur, comps[cur]);
				for (int next : graph[cur]) {
					if (comps[next] == -1) {
						comps[next] = comps[i];
						q.push(next);
					}
				}	
			}
			byComp.push_back(clist);
		}
	}
	vector<bool> withinCycle(n, false);
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i) {
		if (!visited[i]) {
			//printf("spreading through %d\n", i);
			int cur = i;
			while (!visited[orig[cur]]) {
				visited[cur] = true;
				cur = orig[cur];
			}
			withinCycle[cur] = true;
			//printf("stopped cycle at %d\n", cur);
			for (int cm : byComp[comps[i]]) {
				//printf("pseudovisited %d\n", cm);
				visited[cm] = true;
			}
		}
	}
	vector<int> cycleRep(ccomp, 0);
	for (int i = 0; i < n; ++i) {
		if (withinCycle[i]) {
			cycleRep[comps[i]] = i;
		}
	}

	vector<vector<int>> leavesPerComp(ccomp, vector<int>());
	for (int i = 0; i < n; ++i) {
		if (graph[i].size() == 1 && graph[i][0] == orig[i]) {
			leavesPerComp[comps[i]].push_back(i);
		}
	}
	if (ccomp == 1) {
		printf("%lu\n", leavesPerComp[0].size());
		for (int leaf : leavesPerComp[0]) {
			printf("%d %d\n", cycleRep[comps[leaf]] + 1, leaf + 1);
		}
	} else {
		int ans = 0;
		for (int i = 0; i < ccomp; ++i) {
			ans += max(1, (int)leavesPerComp[i].size());
		}
		printf("%d\n", ans);
		for (int comp = 0; comp < ccomp; ++comp) {
			int nextC = (comp + 1) % ccomp;
			printf("%d %d\n", cycleRep[comp] + 1, (leavesPerComp[nextC].empty() ? cycleRep[nextC] : leavesPerComp[nextC][0]) + 1);
			for (int i = 1; i < leavesPerComp[comp].size(); ++i) {
				printf("%d %d\n", cycleRep[comp] + 1, leavesPerComp[comp][i] + 1);
			}
		}
	}
	return 0;
}

//7
//2 3 1 3 4 4 1
//v---------^
//1 -> 2 -> 3 
//^7        ^4 <- 5
//			^6