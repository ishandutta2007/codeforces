#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000000

int n, m, g;
//
struct Edge {
    int to, cap, cur, rev;
};

vector<Edge> graph[14005];
int layer[14005];
int sex[10005]; int v[10005];

void addedge(int from, int to, int cap)
{
    int siz1 = graph[from].size();
    int siz2 = graph[to].size();
    Edge e; e.to = to; e.cap = cap; e.cur = 0; e.rev = siz2;
    graph[from].push_back(e);
    e.to = from; e.cap = 0; e.rev = siz1;
    graph[to].push_back(e);
}

void bfs(void)
{
    layer[1] = 1;
    for (int i = 2; i <= n + m + 2; i++) layer[i] = 0;
    queue<int> que; que.push(1);
    while (!que.empty()) {
        int cur = que.front(); que.pop();
        for (int i = 0; i < graph[cur].size(); i++) {
            Edge e = graph[cur][i];
            if (e.cur < e.cap && !layer[e.to]) {
                layer[e.to] = layer[cur] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int node, int flowamt)
{
    if (node == n + m + 2) return flowamt;
    int remain = flowamt;
    for (int i = 0; i < graph[node].size(); i++) {
        Edge& e = graph[node][i];
        if (e.cur >= e.cap) continue;
        if (layer[e.to] - layer[node] != 1) continue;
        int entered = dfs(e.to, min(remain, e.cap - e.cur));
        remain -= entered;
        e.cur += entered; graph[e.to][e.rev].cur -= entered;
        if (!remain) break;
    }
    return flowamt - remain;
}

int main()
{
    scanf("%d%d%d", &n, &m, &g);
    for (int i = 1; i <= n; i++) scanf("%d", sex + i);
    for (int i = 1; i <= n; i++) scanf("%d", v + i);
    for (int i = 1; i <= n; i++) {
        if (sex[i] == 0) {
            addedge(1, i + 1, v[i]);
        } else {
            addedge(i + 1, n + m + 2, v[i]);
        }
    }
    int ansbase = 0;
    for (int i = 1; i <= m; i++) {
        int s, w, k;
        scanf("%d%d%d", &s, &w, &k);
        vector<int> reqs;
        for (int j = 1; j <= k; j++) {
            int val; scanf("%d", &val); reqs.push_back(val);
        }
        int goodfriend; scanf("%d", &goodfriend);
        if (goodfriend) goodfriend = g;
        ansbase += w;
        if (s == 0) {
            addedge(1, n + i + 1, w + goodfriend);
            for (int j = 0; j < reqs.size(); j++) {
                addedge(n + i + 1, reqs[j] + 1, INF);
            }
        } else {
            addedge(n + i + 1, n + m + 2, w + goodfriend);
            for (int j = 0; j < reqs.size(); j++) {
                addedge(reqs[j] + 1, n + i + 1, INF);
            }
        }
    }
    int ans = ansbase;
    while (1) {
        bfs();
        if (!layer[n + m + 2]) break;
        ans -= dfs(1, INF);
    }
    printf("%d", ans);
    return 0;
}