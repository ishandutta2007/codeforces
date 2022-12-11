#include <bits/stdc++.h>

using namespace std;

void KRound1(int v, stack<int> &visOrder, vector<int> &vis, vector<vector<int>> &graph) {
    vis[v] = true;
    for (int next : graph[v]) {
        if (!vis[next]) KRound1(next, visOrder, vis, graph);
    }
    visOrder.push(v);
}

void KRound2(int v, int sccID, vector<int> &sccs, vector<vector<int>> &graph) {
    if (sccs[v] != -1) return;
    sccs[v] = sccID;
    for (int next : graph[v]) {
        KRound2(next, sccID, sccs, graph);
    }
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, m; scanf("%d %d", &n, &m);
        vector<vector<int>> graph(n, vector<int>());
        vector<vector<int>> revGraph(n, vector<int>());
        for (int i = 0; i < m; ++i) {
            int a, b; scanf("%d %d", &a, &b);
            graph[--a].push_back(--b);
            revGraph[b].push_back(a);
        }
        // get sccs
        // it's possible if there is more than one scc
        stack<int> visOrder;
        vector<int> vis(n);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) KRound1(i, visOrder, vis, graph);
        }
        vector<int> sccID(n, -1);
        int cscc = 0;
        while (!visOrder.empty()) {
            int cur = visOrder.top();
            if (sccID[cur] == -1) {
                KRound2(cur, cscc, sccID, revGraph);
                ++cscc;
            }
            visOrder.pop();
        }
        if (cscc == 1) {
            printf("No\n");
        } else {
            printf("Yes\n");
			vector<int> sccoutDeg(cscc);
			for (int i = 0; i < n; ++i) {
				for (int j : graph[i]) {
					if (sccID[i] != sccID[j]) ++sccoutDeg[sccID[i]];
				}
			}
			int keystone = -1;
			for (int i = 0; i < cscc; ++i) if (sccoutDeg[i] == 0) keystone = i;
            vector<int> half1, half2;
            for (int i = 0; i < n; ++i) {
                if (sccID[i] == keystone) half1.push_back(i);
                else half2.push_back(i);
            }
            printf("%lu %lu\n", half1.size(), half2.size());
            for (int x : half1) printf("%d ", x + 1);
            printf("\n");
            for (int x : half2) printf("%d ", x + 1);
            printf("\n");
        }
    }
    return 0;
}