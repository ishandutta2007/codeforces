#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;
const int MAXM = 2000005;
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

    struct Edge{
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
            if(e[i].w && level[v] == level[u] + 1) {
                LL tmp = DFS(v, min(flow, e[i].w));
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

int n, a[MAXN], id[MAXN];

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        id[a[i]] = i;
    }
    int S = n * 4 + 1, T = S + 1;
    Flow.Init(T);
    for (int i = 1; i <= n; ++i) {
        Flow.Add(S, i, 1);
        Flow.Add(n + i, n * 2 + i, 1);
        Flow.Add(n * 3 + i, T, 1);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = a[i] + a[i]; j <= 50000; j += a[i]) {
            if (!id[j]) continue;
            Flow.Add(i, n + id[j], 1);
            Flow.Add(n * 2 + i, n * 3 + id[j], 1);
        }
    }
    printf("%d\n", Flow.Dinic(S, T));
    for (int i = 1; i <= n; ++i) {
        id[a[i]] = 0;
    }
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}