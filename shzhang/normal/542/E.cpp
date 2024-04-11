#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

int n, m;

vector<int> graph[1005];
int color[1005];

void dfs(int node, vector<int>& vec, int clr)
{
    vec.push_back(node);
    color[node] = clr;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i];
        if (!color[nxt]) {
            dfs(nxt, vec, 3 - clr);
        } else {
            if (color[nxt] != 3 - clr) {
                printf("-1"); exit(0);
            }
        }
    }
}

int dist[1005];
bool vis[1005];

int bfs(int start)
{
    for (int i = 1; i <= n; i++) dist[i] = 0, vis[i] = false;
    queue<int> bfs; bfs.push(start); vis[start] = true;
    while (!bfs.empty()) {
        int node = bfs.front(); bfs.pop();
        for (int i = 0; i < graph[node].size(); i++) {
            int nxt = graph[node][i];
            if (vis[nxt]) continue;
            bfs.push(nxt); vis[nxt] = true;
            dist[nxt] = dist[node] + 1;
        }
    }
    int retv = 0;
    for (int i = 1; i <= n; i++) retv = max(retv, dist[i]);
    return retv;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v); graph[v].push_back(u);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            vector<int> nodes;
            dfs(i, nodes, 1);
            int max_chain = 0;
            for (int j = 0; j < nodes.size(); j++) {
                max_chain = max(max_chain, bfs(nodes[j]));
            }
            ans += max_chain;
        }
    }
    printf("%d", ans);
    return 0;
}