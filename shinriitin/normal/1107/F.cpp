#include <bits/stdc++.h>

using LL = long long;

//Min cost feasible flow or max flow
//modified to long long: inf, dis[], sum, cost, memset(dis, inf)*2, edge.w, addedge(w)
namespace primal_dual {
    const int max_N = 2333; //vertexes number
    const LL inf = 0x3f3f3f3f3f3f3f3fLL; //a number larger than all dis

    int M, vis[max_N], flow;

    LL dis[max_N], sum, cost;

    struct edge {
        int v, c;
        LL w; //vertex, capacity, weight
    };

    std::vector<edge> e; //all edges
    std::vector<int> vec[max_N]; //edge indexes for each vertex

    void adjust(int s) {
        for (int it = 0; it < M; it += 2) {
            int u = e[it ^ 1].v, v = e[it].v;
            e[it].w += dis[v] - dis[u];
            e[it ^ 1].w += dis[u] - dis[v];
        }
        sum += dis[s];
    }

    void spfa(int n, int s, int t) {
        static int Q[max_N];
        int head = 0, tail = 0;
        memset(dis + 1, 0x3f, n * sizeof(LL));
        memset(vis + 1, 0, n * sizeof(int));
        dis[t] = 0, vis[t] = 1, Q[tail++] = t;
        while (head != tail) {
            int u = Q[head++];
            vis[u] = 0;
            if (head == max_N) head = 0;
            for (auto it : vec[u]) {
                if (!e[it ^ 1].c) continue;
                int v = e[it].v;
                auto tmp = dis[u] + e[it ^ 1].w;
                if (dis[v] > tmp) {
                    dis[v] = tmp;
                    if (!vis[v]) {
                        vis[v] = 1, Q[tail++] = v;
                        if (tail == max_N) tail = 0;
                    }
                }
            }
        }
        if (dis[s] == inf) return;
        adjust(s);
    }

    bool dijkstra(int n, int s, int t) {
        memset(dis + 1, 0x3f, n * sizeof(LL));
        memset(vis + 1, 0, n * sizeof(int));
        dis[t] = 0;
        for (int cnt = 1; cnt <= n; ++cnt) {
            int u = 0;
            for (int i = 1; i <= n; ++i) {
                if (vis[i]) continue;
                if (!u || dis[u] > dis[i]) {
                    u = i;
                }
            }
            if (!u) break;
            vis[u] = 1;
            for (auto it : vec[u]) {
                if (!e[it ^ 1].c) continue;
                int v = e[it].v;
                auto tmp = dis[u] + e[it ^ 1].w;
                if (dis[v] > tmp) {
                    dis[v] = tmp;
                }
            }
        }
        if (!vis[s]) return false;
        return adjust(s), true;
    }

    int dfs(int t, int u, int a) {
        if (u == t) return a;
        vis[u] = 1;
        int ret = 0, tmp;
        for (auto it : vec[u]) {
            int v = e[it].v;
            if (e[it].w || vis[v] || !e[it].c) continue;
            tmp = dfs(t, v, std::min(a - ret, e[it].c));
            if (tmp) {
                e[it].c -= tmp;
                e[it ^ 1].c += tmp;
                if ((ret += tmp) == a) break;
            }
        }
        return ret;
    }

    /**
     * Add an edge from u to v
     * @param u from
     * @param v to
     * @param c capacity
     * @param w weight
     */
    void addEdge(int u, int v, int c, LL w) {
        e.push_back({v, c, w});
        vec[u].push_back(M++);
        e.push_back({u, 0, -w});
        vec[v].push_back(M++);
    }

    /**
     * Computing min cost max flow or feasible flow from s to t.
     * The results are stored in variables flow and cost
     * @param n vertexes number
     * @param s from
     * @param t to
     */
    void minCost(int n, int s, int t) {
        int a = ~0U >> 1;
        spfa(n, s, t);
        do {
            while (a) {
                memset(vis + 1, 0, n * sizeof(int));
                int adt = dfs(t, s, a);
                if (!adt) break;
                a -= adt;
                flow += adt;
                cost += adt * sum;
            }
        } while (dijkstra(n, s, t) && sum < 0); //for feasible flow
        //} while (dijkstra(n, s, t)); //for max flow
    }

    /**
     * clear
     * @param n vertexes number
     */
    void clear(int n) {
        e.clear();
        for (int i = 1; i <= n; ++i) {
            std::vector<int>().swap(vec[i]);
        }
        M = sum = flow = cost = 0;
    }
};

int n;

int main() {
    scanf("%d", &n);
    for (int i = 1, a, b, k; i <= n; ++i) {
        scanf("%d%d%d", &a, &b, &k);
        for (int j = 1; j <= n; ++j) {
            LL cost = 1LL * b * std::min(k, j - 1) - a;
            primal_dual::addEdge(i, n + j, 1, cost);
        }
    }
    int s = n + n + 1, t = s + 1;
    for (int i = 1; i <= n; ++i) {
        primal_dual::addEdge(s, i, 1, 0);
        primal_dual::addEdge(n + i, t, 1, 0);
    }
    primal_dual::minCost(t, s, t);
    printf("%lld\n", -primal_dual::cost);
}