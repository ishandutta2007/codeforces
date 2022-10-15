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

using namespace std;

#define ll long long

int n, m, k;

int dist[200005];
vector<int> graph[200005];
vector<int> rgraph[200005];
int path[200005];

void bfs(int origin)
{
    for (int i = 1; i <= n; i++) dist[i] = -1;
    dist[origin] = 0;
    queue<int> que;
    que.push(origin);
    while (!que.empty()) {
        int node = que.front(); que.pop();
        for (int i = 0; i < rgraph[node].size(); i++) {
            int nxt = rgraph[node][i];
            if (dist[nxt] == -1) {
                dist[nxt] = dist[node] + 1;
                que.push(nxt);
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        scanf("%d", path + i);
    }
    bfs(path[k]);
    int minans = 0, maxans = 0;
    for (int i = 1; i < k; i++) {
        int node = path[i];
        if (dist[path[i+1]] > dist[node] - 1) {
            minans++; maxans++;
        } else {
            int good = 0;
            for (int j = 0; j < graph[node].size(); j++) {
                if (dist[graph[node][j]] == dist[node] - 1) good++;
            }
            if (good >= 2) maxans++;
        }
    }
    printf("%d %d", minans, maxans);
    return 0;
}