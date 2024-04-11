#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

struct Edge {
    int to, eid;
};

int n, m;
vector<Edge> graph[200005];
bool vis[200005];
int parent[200005];
int prtindex[200005];
int depth[200005];
vector<pair<int, int> > xedges;

int lca(int a, int b)
{
    if (depth[a] < depth[b]) swap(a, b);
    while (depth[a] > depth[b]) a = parent[a];
    while (a != b) a = parent[a], b = parent[b];
    return a;
}

void path(vector<int>& p, int from, int to)
{
    vector<int> tmp; bool rev = false;
    if (depth[from] < depth[to]) {
        swap(from, to); rev = true;
    }
    while (1) {
        tmp.push_back(from);
        if (from == to) break;
        from = parent[from];
    }
    if (rev) {
        for (int i = ((int)(tmp.size())) - 1; i >= 0; i--) {
            p.push_back(tmp[i]);
        }
    } else {
        for (int i = 0; i < tmp.size(); i++) {
            p.push_back(tmp[i]);
        }
    }
}

void prt(vector<int>& vec)
{
    printf("%d ", (int)vec.size());
    for (int i = 0; i < vec.size(); i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void answer(int e1, int e2)
{
    //printf("%d %d %d %d\n", xedges[e1].first, xedges[e1].second,
    //                        xedges[e2].first, xedges[e2].second);
    if (depth[xedges[e1].first] > depth[xedges[e2].first]) {
        swap(e1, e2);
    }
    int a = xedges[e1].first;
    int b = xedges[e1].second;
    int c = xedges[e2].first;
    int d = xedges[e2].second;
    int l = lca(b, d);
    vector<int> p1, p2, p3;
    if (l == b) {
        path(p1, b, c);
        path(p2, b, d); p2.push_back(c);
        p3.push_back(b); path(p3, a, c);
    } else if (l == d) {
        path(p1, d, c);
        p2.push_back(d); p2.push_back(c);
        path(p3, d, b); path(p3, a, c);
    } else {
        path(p1, l, c);
        path(p2, l, d); p2.push_back(c);
        path(p3, l, b); path(p3, a, c);
    }
    printf("YES\n");
    prt(p1); prt(p2); prt(p3);
}

void dfs(int node, int prt, int prtidx)
{
    parent[node] = prt;
    depth[node] = depth[prt] + 1;
    prtindex[node] = prtidx;
    vis[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        Edge e = graph[node][i];
        if (vis[e.to] && depth[e.to] > depth[node]) {
            xedges.push_back(make_pair(node, e.to));
        } else if (!vis[e.to]) {
            dfs(e.to, node, i);
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        Edge e; e.to = v; e.eid = 0;
        graph[u].push_back(e);
        e.to = u; graph[v].push_back(e);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, 0, 0);
    }
    for (int i = 0; i < xedges.size(); i++) {
        int high = xedges[i].first;
        int low = xedges[i].second;
        int cur = low;
        while (cur != high) {
            if (graph[parent[cur]][prtindex[cur]].eid) {
                answer(graph[parent[cur]][prtindex[cur]].eid - 1, i);
                return 0;
            }
            graph[parent[cur]][prtindex[cur]].eid = i + 1;
            cur = parent[cur];
        }
    }
    printf("NO"); return 0;
}