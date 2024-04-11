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
    int to, wt;
};

int n, m;
vector<Edge> graph[200005];

int dist[200005];
bool vis[200005];
int fro[200005];

set<pair<int, int> > prim;

#define LOG2_N 19

vector<Edge> g[500005];
int depth[500005];
int bdepth[500005];
int parent[500005];
int ancestor[500005][LOG2_N];

void dfs(int node, int prt, int nwt)
{
    //printf("%d %d %d\n", node, prt, nwt);
    depth[node] = depth[prt] + 1;
    bdepth[node] = bdepth[prt] + nwt;
    parent[node] = prt;
    for (int i = 0; i < g[node].size(); i++) {
        int nxt = g[node][i].to;
        if (nxt == prt) continue;
        dfs(nxt, node, g[node][i].wt);

        /* you can do other things here, such as tree DP */
    }
}

int lca(int A, int B)
{
    if (depth[A] < depth[B]) swap(A, B);
    for (int i = 0; i < LOG2_N; i++) {
        if ((depth[A] - depth[B]) & (1 << i)) A = ancestor[A][i];
    }
    if (A == B) return A;
    for (int i = LOG2_N - 1; i >= 0; i--) {
        if (ancestor[A][i] != ancestor[B][i]) {
            A = ancestor[A][i];
            B = ancestor[B][i];
        }
    }
    return parent[A];
}

void updatedist(int node, int val, int from)
{
    //printf("! %d %d\n", node, val);
    if (vis[node]) return;
    prim.erase(make_pair(dist[node], node));
    dist[node] = val;
    fro[node] = from;
    prim.insert(make_pair(dist[node], node));
}

set<pair<int, int> > edges;



int main()
{
    set<pair<int, int> > given_edges;
    scanf("%d%d", &n, &m);
    int wtxor = 0;
    for (int i = 1; i <= m; i++) {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        given_edges.insert(make_pair(u, v));
        Edge e; e.to = v; e.wt = w;
        wtxor ^= w;
        graph[u].push_back(e);
        e.to = u; graph[v].push_back(e);
    }
    for (int i = 0; i < graph[1].size(); i++) {
        int nxt = graph[1][i].to; dist[nxt] = graph[1][i].wt;
    }
    vector<int> nonzero;
    for (int i = 2; i <= n; i++) {
        fro[i] = 1;
        if (dist[i] > 0) nonzero.push_back(i);
        prim.insert(make_pair(dist[i], i));
    }
    vis[1] = true;
    ll mst = 0;
    ll freeedges = ((ll)n * (ll)(n - 1)) / 2LL - (ll)m;
    while (!prim.empty()) {
        pair<int, int> cur = *prim.begin();
        //printf("%d %d\n", cur.first, cur.second);
        prim.erase(cur);
        mst += (ll)(cur.first);
        int cnode = cur.second;
        pair<int, int> pr = make_pair(cnode, fro[cnode]);
        edges.insert(pr);
        if (!(given_edges.count(pr) ||
        given_edges.count(make_pair(pr.second, pr.first)))) {
            freeedges--;
            Edge e; e.to = pr.second; e.wt = 1;
            g[pr.first].push_back(e);
            e.to = pr.first;
            g[pr.second].push_back(e);
        }
        set<int> st2;
        for (int i = 0; i < graph[cnode].size(); i++) {
            Edge nxt = graph[cnode][i];
            st2.insert(nxt.to);
            if (nxt.wt < dist[nxt.to]) {
                updatedist(nxt.to, nxt.wt, cnode);
            }
        }
        vector<int> nonzero2;
        for (int i = 0; i < nonzero.size(); i++) {
            if (st2.count(nonzero[i])) {
                nonzero2.push_back(nonzero[i]);
            } else {
                updatedist(nonzero[i], 0, cnode);
            }
        }
        swap(nonzero, nonzero2);
        vis[cnode] = true;
        prim.erase(make_pair(dist[cnode], cnode));
    }
    if (freeedges) {
        printf("%lld", mst); return 0;
    }
    ll ans = mst + wtxor;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int nxt = graph[i][j].to;
            if (edges.count(make_pair(i, nxt))
            || edges.count(make_pair(nxt, i))) {
                Edge e2 = graph[i][j]; e2.wt = 0;
                g[i].push_back(e2);
            }
        }
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++) ancestor[i][0] = parent[i];
    for (int pwr = 1; pwr < LOG2_N; pwr++) {
        for (int i = 1; i <= n; i++) {
            ancestor[i][pwr] = ancestor[ancestor[i][pwr-1]][pwr-1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            int nxt = graph[i][j].to;
            if (!(edges.count(make_pair(i, nxt))
            || edges.count(make_pair(nxt, i)))) {
                int fedgecnt = bdepth[i] + bdepth[nxt] - 2 * bdepth[lca(i, nxt)];
                if (fedgecnt) {
                    ans = min(ans, mst + (ll)graph[i][j].wt);
                }
            }
        }
    }
    printf("%lld", ans);
    return 0;
}