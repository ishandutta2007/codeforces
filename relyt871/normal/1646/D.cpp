#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200005;

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

int n, choose[MAXN], dp[MAXN][2], fr[MAXN], w[MAXN];
LL ds[MAXN][2];
vector<int> tree[MAXN];

void DFS1(int u, int fa) {
    dp[u][0] = 0;
    dp[u][1] = 1;
    ds[u][0] = 1;
    ds[u][1] = tree[u].size();
    for (auto v : tree[u]) {
        if (v == fa) continue;
        DFS1(v, u);
        if (dp[v][0] > dp[v][1] || (dp[v][0] == dp[v][1] && ds[v][0] < ds[v][1])) {
            dp[u][0] += dp[v][0];
            ds[u][0] += ds[v][0];
            fr[v] = 0;
        } else {
            dp[u][0] += dp[v][1];
            ds[u][0] += ds[v][1];
            fr[v] = 1;
        }
        dp[u][1] += dp[v][0];
        ds[u][1] += ds[v][0];
    }
}

void DFS2(int u, int fa, int t) {
    choose[u] = t;
    for (auto v : tree[u]) {
        if (v == fa) continue;
        if (t == 0) {
            DFS2(v, u, fr[v]);
        } else {
            DFS2(v, u, 0);
        }
    }
}

void solve() {
    read(n);
    if (n == 2) {
        printf("%d %d\n%d %d\n", 2, 2, 1, 1);
        return;
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS1(1, 0);
    if (dp[1][0] > dp[1][1] || (dp[1][0] == dp[1][1] && ds[1][0] < ds[1][1])) {
        DFS2(1, 0, 0);
        printf("%d %lld\n", dp[1][0], ds[1][0]);
    } else {
        DFS2(1, 0, 1);
        printf("%d %lld\n", dp[1][1], ds[1][1]);
    }
    for (int i = 1; i <= n; ++i) {
        if (choose[i]) {
            w[i] = tree[i].size();
        } else {
            w[i] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", w[i]);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}