#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const int MAXN = 500005;

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

int n, siz[MAXN], fid[MAXN], bsiz[MAXN << 1];
vector<int> stk[MAXN];

struct Edge {
    int v, w, nxt;
} e[MAXN << 1];
int first[MAXN], eCnt;

inline void AddEdge(int u, int v, int w) {
    e[++eCnt].v = v;
    e[eCnt].w = w;
    e[eCnt].nxt = first[u];
    first[u] = eCnt;
}

void DFS(int u, int fa) {
    siz[u] = 1;
    for (int i = first[u]; i; i = e[i].nxt) {
        int v = e[i].v, w = e[i].w;
        if (v == fa) continue;
        fid[v] = stk[w].back();
        stk[w].push_back(v);
        DFS(v, u);
        siz[u] += siz[v];
        bsiz[v] += siz[v];
        bsiz[fid[v]] -= siz[v];
        stk[w].pop_back();
    }
}

void solve() {
    read(n);
    for (int i = 1, u, v, w; i < n; ++i) {
        read(u); read(v); read(w);
        AddEdge(u, v, w);
        AddEdge(v, u, w);
    }
    for (int i = 1; i <= n; ++i) {
        bsiz[n + i] = n;
        stk[i].push_back(n + i);
    }
    DFS(1, 0);
    LL ans = 0;
    for (int i = 2; i <= n; ++i) {
        ans += 1LL * bsiz[i] * bsiz[fid[i]];
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}