#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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

int n, k, s[MAXN];
vector<int> tree[MAXN];
map<int, LL> dp[MAXN];
LL mxd[MAXN];

void DFS(int u) {
    mxd[u] = s[u];
    for (auto v : tree[u]) {
        DFS(v);
        mxd[u] = max(mxd[u], mxd[v] + s[u]);
    }
}

LL DP(int u, int c) {
    if (c == 0) return 0;
    if (c == 1) return mxd[u];
    if (!tree[u].size()) return 1LL * s[u] * c;
    if (dp[u].count(c)) {
        return dp[u][c];
    }
    LL mx = 0;
    int c1 = c / tree[u].size(), c2 = c % tree[u].size();
    for (auto v : tree[u]) {
        mx += DP(v, c1);
        if (c2) DP(v, c1 + 1);
    }
    if (c2) {
        vector<LL> dif;
        for (auto v : tree[u]) {
            dif.push_back(DP(v, c1 + 1) - DP(v, c1));
        }
        sort(dif.begin(), dif.end());
        reverse(dif.begin(), dif.end());
        for (int i = 0; i < c2; ++i) {
            mx += dif[i];
        }
    }
    return dp[u][c] = mx + 1LL * s[u] * c;
}

void solve() {
    read(n); read(k);
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
        dp[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
        int p; read(p);
        tree[p].push_back(i);
    }
    for (int i = 1; i <= n; ++i) {
        read(s[i]);
    }
    DFS(1);
    printf("%lld\n", DP(1, k));
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}