#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1005;
const int MAXM = 100005;
const LL INF = 1e17;

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
        int v, nxt; LL w;
    } e[MAXM << 1];
    int first[MAXN], used[MAXN], eCnt;

    inline void AddEdge(int u, int v, LL w) {
        e[++eCnt].v = v;
        e[eCnt].w = w;
        e[eCnt].nxt = first[u];
        first[u] = eCnt;
    }

    inline void Add(int u, int v, LL w) {
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

    LL DFS(int u, LL flow) {
        if (u == T) return flow;
        LL ret = 0;
        for (int i = used[u]; i; i = e[i].nxt, used[u] = i) {
            int v = e[i].v;
            if (e[i].w && level[v] == level[u] + 1) {
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

    LL Dinic(int s, int t) {
        S = s; T = t;
        LL ret = 0;
        while (BFS()) {
            ret += DFS(S, INF);
        }
        return ret;
    }
} Flow;

int n, m, q[MAXN], q2[MAXN], pos[MAXN];
vector<int> lim[MAXN];
LL a[MAXN], ans[MAXN];

void Work(LL L, LL R, int l, int r) {
    if (l > r) return;
    if (L == R) {
        for (int i = l; i <= r; ++i) {
            ans[q[i]] = L;
        }
        return;
    }
    LL mid = (L + R) >> 1;
    int S = r - l + 2, T = S + 1;
    Flow.Init(T);
    for (int i = l; i <= r; ++i) {
        if (a[q[i]] <= mid) {
            Flow.Add(S, i - l + 1, 1);
        } else {
            Flow.Add(i - l + 1, T, 1);
        }
        for (auto v : lim[q[i]]) {
            if (l <= pos[v] && pos[v] <= r) {
                Flow.Add(pos[v] - l + 1, i - l + 1, INF);
            }
        }
    }
    Flow.Dinic(S, T);
    int tl = l - 1, tr = r + 1;
    for (int i = l; i <= r; ++i) {
        if (Flow.level[i - l + 1] != -1) {
            q2[++tl] = q[i];
        } else {
            q2[--tr] = q[i];
        }
    }
    for (int i = l; i <= r; ++i) {
        q[i] = q2[i];
        pos[q[i]] = i;
    }
    Work(L, mid, l, tl);
    Work(mid + 1, R, tr, r);
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        q[i] = pos[i] = i;
    }
    for (int i = 1, u, v; i <= m; ++i) {
        read(u); read(v);
        lim[u].push_back(v);
    }
    Work(-1e15, 1e15, 1, n);
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
    }
}

int main() {
    solve();
    return 0;
}