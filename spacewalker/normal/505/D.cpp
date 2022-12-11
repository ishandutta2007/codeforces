#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> unDir;
vector<bool> hasCycleReach;
vector<bool> inCallStack;
vector<bool> vis;

void popCycleStarts(int i) {
	vis[i] = true;
	inCallStack[i] = true;
	for (int next : graph[i]) {
		if (!vis[next]) {
			vis[next] = true;
			popCycleStarts(next);
		} else if (inCallStack[next]) {
			hasCycleReach[i] = true;
		}
	}
	inCallStack[i] = false;
}

int main() {
	int n, m; scanf("%d %d", &n, &m);
	graph = unDir = vector<vector<int>>(n, vector<int>());
	hasCycleReach = inCallStack = vis = vector<bool>(n, false);
	for (int i = 0; i < m; ++i) {
		int u, v; scanf("%d %d", &u, &v);
		graph[--u].push_back(--v);
		unDir[u].push_back(v);
		unDir[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i]) {
			popCycleStarts(i);
		}
	}
	vis = vector<bool>(n, false);
	queue<int> cycleQ;
	for (int i = 0; i < n; ++i) {
		if (hasCycleReach[i]) {
			cycleQ.push(i);
		}
	}
	while (!cycleQ.empty()) {
		int cur = cycleQ.front(); cycleQ.pop();
		hasCycleReach[cur] = true;
		for (int next : unDir[cur]) {
			if (!vis[next]) {
				vis[next] = true;
				cycleQ.push(next);
			}
		}
	}
	int noCycleComp = 0;
	for (int i = 0; i < n; ++i) {
		if (!hasCycleReach[i]) {
			noCycleComp++;
			hasCycleReach[i] = true;
			cycleQ.push(i);
			while (!cycleQ.empty()) {
				int cur = cycleQ.front(); cycleQ.pop();
				hasCycleReach[cur] = true;
				for (int next : unDir[cur]) {
					if (!vis[next]) {
						vis[next] = true;
						cycleQ.push(next);
					}
				}
			}
		}
	}
	printf("%d\n", n - noCycleComp);
	return 0;
}