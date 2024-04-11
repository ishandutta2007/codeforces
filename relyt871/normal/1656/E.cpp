#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, ans[MAXN];
vector<int> tree[MAXN];

void DFS(int u, int fa, int x) {
    ans[u] = x * tree[u].size();
    for (auto v : tree[u]) {
        if (v == fa) continue;
        DFS(v, u, -x);
    }
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        tree[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    DFS(1, 0, 1);
    for (int i = 1; i <= n; ++i) {
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}