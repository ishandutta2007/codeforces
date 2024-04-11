// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int fa[N], L[N], R[N], ans, n;

vector<int> g[N];

void inline clr() {
    for (int i = 1; i <= n; i++) fa[i] = 0, g[i].clear();
    ans = 0;
}

LL dfs(int u) {
    LL s = 0;
    for (int v: g[u]) {
        s += dfs(v);
    }
    if (s < L[u]) {
        s = R[u];
        ans++;
    } else if (s > R[u]) {
        s = R[u];
    }
    return s;
}

int main() {
    int T; read(T);
    while (T--) {
        read(n);
        for (int i = 2; i <= n; i++) read(fa[i]), g[fa[i]].pb(i);
        for (int i = 1; i <= n; i++) read(L[i]), read(R[i]);
        dfs(1);
        printf("%d\n", ans);
        clr();
    }
    return 0;
}