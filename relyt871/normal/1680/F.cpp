#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 1000005;

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

mt19937_64 Rand(time(0));

int n, m, ban, U[MAXN], V[MAXN], vis[MAXN], in[MAXN];
int col[MAXN], q[MAXN], head, tail;
ULL sum[MAXN], all;
unordered_map<ULL, int> Map;

struct Edge {
    int v, nxt;
} e[MAXN << 1];
int first[MAXN], eCnt;

inline void AddEdge(int u, int v) {
    e[++eCnt].v = v;
    e[eCnt].nxt = first[u];
    first[u] = eCnt;
}

bool Bipartite() {
    for (int i = 1; i <= n; ++i) {
        col[i] = -1;
    }
    col[1] = 0;
    q[head = tail = 1] = 1;
    while (head <= tail) {
        int u = q[head++];
        for (int i = first[u]; i; i = e[i].nxt) {
            if ((i >> 1) == ban) continue;
            int v = e[i].v;
            if (col[v] != -1) {
                if (col[u] == col[v]) {
                    return 0;
                }
            } else {
                col[v] = col[u] ^ 1;
                q[++tail] = v;
            }
        }
    }
    return 1;
}

void DFS(int u) {
    vis[u] = 1;
    for (int i = first[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (vis[v]) continue;
        in[i >> 1] = 1;
        DFS(v);
    }
}

void DFS2(int u) {
    vis[u] = 1;
    for (int i = first[u]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (vis[v]) continue;
        DFS2(v);
        Map[sum[v]] = (i >> 1);
        all ^= sum[v];
        sum[u] ^= sum[v];
    }
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        first[i] = 0;
    }
    eCnt = 1;
    for (int i = 1; i <= m; ++i) {
        read(U[i]); read(V[i]);
        AddEdge(U[i], V[i]);
        AddEdge(V[i], U[i]);
        in[i] = 0;
    }
    ban = 0;
    if (Bipartite()) {
        puts("YES");
        for (int i = 1; i <= n; ++i) {
            putchar('0' + col[i]);
        }
        puts("");
        return;
    }
    all = 0;
    Map.clear();
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
        sum[i] = 0;
    }
    DFS(1);
    for (int i = 1; i <= m; ++i) {
        if (in[i]) continue;
        ULL x = Rand();
        sum[U[i]] ^= x;
        sum[V[i]] ^= x;
        Map[x] = i;
        all ^= x;
    }
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    DFS2(1);
    if (!Map.count(all)) {
        puts("NO");
        return;
    }
    ban = Map[all];
    assert(Bipartite());
    puts("YES");
    int flag = col[U[ban]];
    for (int i = 1; i <= n; ++i) {
        putchar('0' + (col[i] == flag));
    }
    puts("");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}