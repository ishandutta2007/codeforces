#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int) 1e2 + 5;

int n, m;
int xl[MAXN], xr[MAXN], yl[MAXN], yr[MAXN];

set<int> xs, ys;

namespace Dinic {
    const int MAXV = 500 + 5;
    const int MAXE = (int) 1e6 + 5;
    
    const int INF = 0x3f3f3f3f;
    
    int head[MAXV], nxt[MAXE], ed, st, sd;
    struct Edge {
        int u, v, cap;
        
        Edge() = default;
        Edge(int _u, int _v, int _c): u(_u), v(_v), cap(_c) {}
    } e[MAXE];
    
    void addEdge(int u, int v, int cap, int icap = 0) {
        nxt[ed] = head[u]; head[u] = ed; e[ed++] = Edge(u, v, cap);
        nxt[ed] = head[v]; head[v] = ed; e[ed++] = Edge(v, u, icap);
    }
    
    int dist[MAXV], cur[MAXV];
    
    bool modLabel() {
        queue<int> que;
        
        memset(dist, -1, sizeof dist);
        dist[st] = 0; que.push(st);
        while (!que.empty()) {
            int now = que.front(); que.pop();
            for (int i = head[now]; i != -1; i = nxt[i]) {
                if (e[i].cap == 0 || dist[e[i].v] != -1) continue;
                dist[e[i].v] = dist[now] + 1;
                que.push(e[i].v);
            }
        }
        
        return dist[sd] != -1;
    }
    
    int augment(int now, int flow) {
        if (now == sd || flow == 0) return flow;
        int res = 0;
        for (int &i = cur[now]; i != -1; i = nxt[i]) {
            if (e[i].cap == 0 || dist[e[i].v] != dist[now] + 1) continue;
            int tmp = augment(e[i].v, min(e[i].cap, flow));
            e[i].cap -= tmp; e[i ^ 1].cap += tmp;
            res += tmp; flow -= tmp;
            if (flow == 0) break;
        }
        return res;
    }
    
    int dinic() {
        int res = 0;
        while (modLabel()) {
            memcpy(cur, head, sizeof head);
            res += augment(st, INF);
        }
        return res;
    }
    
    void build() {
        memset(head, -1, sizeof head); ed = 0;
        
        vector<int> x, y;
        for (int i : xs) {
            // cerr << "x: " << i << endl;
            x.push_back(i);
        }
        for (int i : ys) {
            // cerr << "y: " << i << endl;
            y.push_back(i);
        }
        
        int n_row = x.size() - 1;
        int n_col = y.size() - 1;
        
        st = 0; sd = n_row + n_col + 1;
        for (int i = 1; i <= n_row; ++i) {
            addEdge(st, i, x[i] - x[i - 1]);
        }
        for (int i = 1; i <= n_col; ++i) {
            addEdge(n_row + i, sd, y[i] - y[i - 1]);
        }
        
        for (int i = 1; i <= n_row; ++i) {
            for (int j = 1; j <= n_col; ++j) {
                bool is_black = false;
                for (int k = 1; k <= m; ++k) {
                    if (xl[k] <= x[i - 1] + 1 && x[i] <= xr[k] && yl[k] <= y[j - 1] + 1 && y[j] <= yr[k]) {
                        is_black = true; break;
                    }
                }
                if (is_black) {
                    // cerr << "black: " << i << " " << j << endl;
                    addEdge(i, n_row + j, INF);
                }
            }
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    xs.insert(0); xs.insert(n);
    ys.insert(0); ys.insert(n);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", xl + i, yl + i, xr + i, yr + i);
        xs.insert(xl[i] - 1);
        xs.insert(xr[i]);
        ys.insert(yl[i] - 1);
        ys.insert(yr[i]);
    }
    
    Dinic::build();
    
    printf("%d\n", Dinic::dinic());
    
    return 0;
}