#include <bits/stdc++.h>

using namespace std;

const int maxn = 5005;

// dinic's algorithm from e-maxx

namespace flow {
    const int MAXN = 10005; //  
    const int INF = 1000000000; // -

    struct edge {
        int a, b, cap, flow;
    };

    int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
    vector<edge> e;
    vector<int> g[MAXN];

    void add_edge (int a, int b, int cap) {
        edge e1 = { a, b, cap, 0 };
        edge e2 = { b, a, 0, 0 };
        g[a].push_back ((int) e.size());
        e.push_back (e1);
        g[b].push_back ((int) e.size());
        e.push_back (e2);
    }

    bool bfs() {
        int qh=0, qt=0;
        q[qt++] = s;
        memset (d, -1, n * sizeof d[0]);
        d[s] = 0;
        while (qh < qt && d[t] == -1) {
            int v = q[qh++];
            for (size_t i=0; i<g[v].size(); ++i) {
                int id = g[v][i],
                to = e[id].b;
                if (d[to] == -1 && e[id].flow < e[id].cap) {
                    q[qt++] = to;
                    d[to] = d[v] + 1;
                }
            }
        }
        return d[t] != -1;
    }

    int dfs (int v, int flow) {
        if (!flow)  return 0;
        if (v == t)  return flow;
        for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
            int id = g[v][ptr[v]],
            to = e[id].b;
            if (d[to] != d[v] + 1)  continue;
            int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id^1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int dinic() {
        int flow = 0;
        for (;;) {
            if (!bfs())  break;
            memset (ptr, 0, n * sizeof ptr[0]);
            while (int pushed = dfs (s, INF))
                flow += pushed;
        }
        return flow;
    }
};

int n, m;
bool e[maxn][maxn];

bool can(int give, bool print) {
    int start = flow::MAXN - 2;
    int end = flow::MAXN - 3;
    flow::n = flow::MAXN - 1;
    flow::s = start;
    flow::t = end;
    flow::e.clear();
    for (int i = 0; i < flow::MAXN; i++) {
        flow::g[i].clear();
    }

    int edgeidx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (e[i][j]) {
                flow::add_edge(i, n+edgeidx, 1);
                flow::add_edge(j, n+edgeidx, 1);
                flow::add_edge(n+edgeidx, end, 1);
                edgeidx++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        flow::add_edge(start, i, give);
    }
    int k = flow::dinic();
    assert(k <= m);
    if (print) {
        assert(k == m);
        edgeidx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (e[i][j]) {
                    if (flow::e[edgeidx*6 + 0].flow == 1) {
                        printf("%d %d\n", i+1, j+1);
                    } else {
                        assert(flow::e[edgeidx*6 + 2].flow == 1);
                        printf("%d %d\n", j+1, i+1);
                    }
                    edgeidx++;
                }
            }
        }
    }
    return k == m;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        e[a][b] = e[b][a] = true;
    }

    int lo = 0, hi = maxn, best = 0;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (can(mid, false)) {
            best = mid;
            hi = mid-1;
        } else {
            lo = mid+1;
        }
    }

    printf("%d\n", best);
    can(best, true);
}