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
    int to, len;
};

vector<Edge> graph[5000005];
vector<int> ograph[200005];
ll dist[5000005];

int n, m;

void Bfs(int nodes)
{
    dist[1] = 0;
    for (int i = 2; i <= nodes; i++) dist[i] = 1000000000;
    deque<int> bfs;
    bfs.push_back(1);
    while (!bfs.empty()) {
        int cur = bfs.front(); bfs.pop_front();
        for (int i = 0; i < graph[cur].size(); i++) {
            Edge e = graph[cur][i];
            if (dist[e.to] > dist[cur] + e.len) {
                dist[e.to] = dist[cur] + e.len;
                if (e.len == 0) {
                    bfs.push_front(e.to);
                } else {
                    bfs.push_back(e.to);
                }
            }
        }
    }
    //for (int i = 1; i <= nodes; i++) {
    //    printf("%lld ", dist[i]);
    //}
}

void dijkstra(int nodes)
{
    set<pair<ll, int> > dij;
    dist[1] = 0;
    for (int i = 2; i <= nodes; i++) dist[i] = 1000000000000000000LL;
    for (int i = 1; i <= nodes; i++) {
        dij.insert(make_pair(dist[i], i));
    }

    while (!dij.empty()) {
        pair<ll, int> cur = *dij.begin();
        dij.erase(dij.begin());
        int node = cur.second;
        for (int i = 0; i < graph[node].size(); i++) {
            Edge e = graph[node][i];
            if (dist[e.to] > dist[node] + e.len) {
                dij.erase(make_pair(dist[e.to], e.to));
                dist[e.to] = dist[node] + e.len;
                dij.insert(make_pair(dist[e.to], e.to));
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        ograph[u].push_back(v);
        Edge e; e.to = v; e.len = 0;
        graph[u].push_back(e);
        e.to = n + u;
        graph[n + v].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        Edge e; e.to = n + i; e.len = 1;
        graph[i].push_back(e);
        e.to = i;
        graph[n + i].push_back(e);
    }
    Bfs(2 * n);
    int min_trans = min(dist[n], dist[n * 2]);
    if (min_trans <= 20) {
        for (int i = 1; i <= 2 * n; i++) graph[i].clear();
        for (int layer = 0; layer <= 20; layer++) {
            for (int i = 1; i <= n; i++) {
                if (layer != 20) {
                    Edge e; e.to = (layer + 1) * n + i; e.len = 0;
                    graph[layer * n + i].push_back(e);
                }
                for (int j = 0; j < ograph[i].size(); j++) {
                    if (layer % 2 == 0) {
                        Edge e; e.to = layer * n + ograph[i][j]; e.len = 1;
                        graph[layer * n + i].push_back(e);
                    } else {
                        Edge e; e.to = layer * n + i; e.len = 1;
                        graph[layer * n + ograph[i][j]].push_back(e);
                    }
                }
            }
        }
        Bfs(21 * n);
        ll ans = 1000000000;
        for (int i = 0; i <= 20; i++) {
            ans = min(ans, dist[(i + 1) * n] + (1 << i) - 1);
        }
        printf("%lld", ans);
    } else {
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                if (((graph[i][j].to - 1) / n) != (i / n)) {
                    graph[i][j].len = 1000000000;
                } else {
                    graph[i][j].len = 1;
                }
            }
        }
        dijkstra(2 * n);
        int ans = 1;
        ll Dist = min(dist[n], dist[n * 2]);
        for (int i = 1; i <= Dist / 1000000000; i++) {
            ans += ans;
            if (ans >= 998244353) ans -= 998244353;
        }
        ans--;
        if (ans < 0) ans += 998244353;
        ans += Dist % 1000000000;
        if (ans >= 998244353) ans -= 998244353;
        printf("%d", ans);
    }
    return 0;
}