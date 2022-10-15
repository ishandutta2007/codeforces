#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <utility>

using namespace std;

#define ll long long

vector<int> graph[200005];
vector<int> revgraph[200005];
int indeg[200005];
int n, m;
bool ans[200005];
bool vis[200005];
bool vis2[200005];

void dfs(vector<int>* gr, bool* v, int node)
{
    if (v[node]) {
        //printf("%d already vis\n", node);
        return;
    }
    //printf("vis %d (nxt %d)\n", node, (int)gr[node].size());
    v[node] = true;
    for (int i = 0; i < gr[node].size(); i++) {
        dfs(gr, v, gr[node][i]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int a, b; scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        revgraph[b].push_back(a); indeg[b]++;
    }
    queue<int> topo;
    int topocnt = 0;
    for (int i = 1; i <= n; i++) if (!indeg[i]) topo.push(i);
    while (!topo.empty()) {
        int nxt = topo.front(); topo.pop();
        topocnt++;
        for (int i = 0; i < graph[nxt].size(); i++) {
            int nxt2 = graph[nxt][i];
            indeg[nxt2]--;
            if (indeg[nxt2] == 0) topo.push(nxt2);
        }
    }
    if (topocnt != n) {
        printf("-1"); return 0;
    }
    int anscnt = 0;
    //printf("!!! %d\n", (int)graph[26].size());
    for (int i = 1; i <= n; i++) {
        if (!(vis[i] || vis2[i])) {
            //printf("%d\n", i);
            ans[i] = true; anscnt++;
        }
        dfs(graph, vis, i);
        dfs(revgraph, vis2, i);
    }
    printf("%d\n", anscnt);
    for (int i = 1; i <= n; i++) {
        printf("%c", ans[i] ? 'A' : 'E');
    }
    return 0;
}