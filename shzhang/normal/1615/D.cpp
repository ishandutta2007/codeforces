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

struct Edge {
    int to, val;
};

vector<Edge> graph[200005];
int u[200005], v[200005], x[200005];
bool vis[200005];
int group[200005];

int n, m;

void addedge(int from, int to, int val)
{
    Edge e; e.to = to; e.val = val;
    graph[from].push_back(e);
    e.to = from; graph[to].push_back(e);
}

void dfs(int node, int cgroup)
{
    group[node] = cgroup;
    vis[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        int nxt = graph[node][i].to;
        if (vis[nxt]) continue;
        dfs(nxt, cgroup ^ graph[node][i].val);
    }
}

void work()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        graph[i].clear(); vis[i] = false;
    }
    for (int i = 1; i < n; i++) {
        scanf("%d%d%d", u + i, v + i, x + i);
        if (x[i] != -1) {
            int cnt = 0;
            for (int j = 0; j < 30; j++) {
                if (x[i] & (1 << j)) cnt++;
            }
            addedge(u[i], v[i], cnt % 2);
        }
    }
    for (int i = 1; i <= m; i++) {
        int a, b, p; scanf("%d%d%d", &a, &b, &p);
        addedge(a, b, p);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 0);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int nxt = graph[i][j].to;
            if (group[nxt] != (group[i] ^ graph[i][j].val)) {
                printf("NO\n"); return;
            }
        }
    }
    printf("YES\n");
    for (int i = 1; i < n; i++) {
        printf("%d %d %d\n", u[i], v[i], (x[i] == -1 ? (group[u[i]] ^ group[v[i]]) : x[i]));
    }
}

int main()
{
    int t; scanf("%d", &t);
    for (int i = 1; i <= t; i++) work();
    return 0;
}