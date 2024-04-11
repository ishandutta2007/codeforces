#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 505;
const int MAXN = 300005;
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

int n, m, U[MAXN], V[MAXN], W[MAXN];
int dis[N][N];

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            dis[i][j] = (i == j? 0 : INF);
        }
    }
    for (int i = 1; i <= m; ++i) {
        read(U[i]); read(V[i]); read(W[i]);
        dis[U[i]][V[i]] = dis[V[i]][U[i]] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (i == k) continue;
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    LL ans = 1e18;
    for (int i = 1; i <= m; ++i) {
        int u = U[i], v = V[i], w = W[i], c = INF;
        c = min(dis[1][u] + dis[v][n], dis[1][v] + dis[u][n]) + 1;
        for (int j = 1; j <= n; ++j) {
            c = min(c, dis[1][j] + dis[j][n] + min(dis[u][j], dis[v][j]) + 2);
        }
        ans = min(ans, 1LL * w * c);
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}