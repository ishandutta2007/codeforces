#include<bits/stdc++.h>
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

int n, a[MAXN], as[MAXN], id[MAXN], ans;
vector<int> tree[MAXN];
set<int> S[MAXN];

void DFS(int u, int fa) {
    id[u] = u;
    S[u].insert(as[u]);
    bool flag = 0;
    for (auto v : tree[u]) {
        if (v == fa) continue;
        as[v] = as[u] ^ a[v];
        DFS(v, u);
        if (S[id[u]].size() < S[id[v]].size()) {
            swap(id[u], id[v]);
        }
        for (auto x : S[id[v]]) {
            if (S[id[u]].count(x ^ a[u])) {
                flag = 1;
            }
        }
        for (auto x : S[id[v]]) {
            S[id[u]].insert(x);
        }
    }
    if (flag) {
        ++ans;
        S[id[u]].clear();
    }
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    as[1] = 1;
    DFS(1, 0);
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}