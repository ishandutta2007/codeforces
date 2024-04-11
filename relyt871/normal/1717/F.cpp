#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 20022;
const int MAXM = 1000005;
const int INF = 0x3f3f3f3f;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

struct MaxFlow {
    int n, S, T;
    int level[MAXN], q[MAXN], head, tail;

    struct Edge {
        int v, w, nxt;
    } e[MAXM << 1];
    int first[MAXN], used[MAXN], eCnt;

    inline void AddEdge(int u, int v, int w) {
        e[++eCnt].v = v;
        e[eCnt].w = w;
        e[eCnt].nxt = first[u];
        first[u] = eCnt;
    }

    inline void Add(int u, int v, int w) {
        AddEdge(u, v, w);
        AddEdge(v, u, 0);
    }

    void Init(int _n) {
        n = _n;
        for (int i = 1; i <= n; ++i) {
            first[i] = 0;
        }
        eCnt = 1;
    }

    bool BFS() {
        for (int i = 1; i <= n; ++i) {
            level[i] = -1;
            used[i] = first[i];
        }
        level[S] = 0;
        q[head = tail = 1] = S;
        while (head <= tail) {
            int u = q[head++];
            if (u == T) return 1;
            for (int i = first[u]; i; i = e[i].nxt) {
                int v = e[i].v;
                if (e[i].w && level[v] == -1) {
                    level[v] = level[u] + 1;
                    q[++tail] = v;
                }
            }
        }
        return 0;
    }

    int DFS(int u, int flow) {
        if (u == T) return flow;
        int ret = 0;
        for (int i = used[u]; i; i = e[i].nxt, used[u] = i) {
            int v = e[i].v;
            if (e[i].w && level[v] == level[u] + 1) {
                int tmp = DFS(v, min(flow, e[i].w));
                e[i].w -= tmp;
                e[i ^ 1].w += tmp;
                flow -= tmp;
                ret += tmp;
                if (!flow) break;
            }
        }
        if (!ret) level[u] = -1;
        return ret;
    }

    int Dinic(int s, int t) {
        S = s; T = t;
        int ret = 0;
        while (BFS()) {
            ret += DFS(S, INF);
        }
        return ret;
    }
} Flow;

int n, m, s[MAXN], a[MAXN], b[MAXN], U[MAXN], V[MAXN], id[MAXN];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(s[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    int S = n + m + 1, T = S + 1, TT = T + 1;
    Flow.Init(TT);
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        U[i] = u; V[i] = v;
        ++b[u]; ++b[v];
        Flow.Add(S, i, 1);
        Flow.Add(i, m + u, 1);
        id[i] = Flow.eCnt;
        Flow.Add(i, m + v, 1);
    }
    int tmp = m;
    for (int i = 1; i <= n; ++i) {
        if (s[i]) {
            if (abs(a[i]) > b[i] || a[i] + b[i] < 0 || ((a[i] + b[i]) & 1)) {
                puts("NO");
                return;
            }
            int add = (a[i] + b[i]) / 2;
            Flow.Add(m + i, T, add);
            tmp -= add;
        } else {
            Flow.Add(m + i, TT, m);
        }
    }
    if (tmp < 0) {
        puts("NO");
        return;
    }
    Flow.Add(TT, T, tmp);
    if (Flow.Dinic(S, T) < m) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i <= m; ++i) {
        if (Flow.e[id[i]].w) {
            printf("%d %d\n", V[i], U[i]);
        } else {
            printf("%d %d\n", U[i], V[i]);
        }
    }
}

int main() {
    solve();
    return 0;
}