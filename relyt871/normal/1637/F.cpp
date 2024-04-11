#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 200006;

template <typename T> inline void read(T &WOW) {
    T x = 0, flag = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '0') flag = -1;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    WOW = flag * x;
}

int n, h[MAXN];
vector<int> tree[MAXN];
LL ans;

int DFS(int u, int fa) {
    int mx = 0, mx2 = 0;
    for (auto v : tree[u]) {
        if (v == fa) continue;
        int son = DFS(v, u);
        if (son > mx) {
            mx2 = mx;
            mx = son;
        } else if (son > mx2) {
            mx2 = son;
        }
    }
    if (fa) {
        if (h[u] > mx) {
            ans += h[u] - mx;
            mx = h[u];
        }
    } else {
        ans += max(0, h[u] - mx);
        ans += max(0, h[u] - mx2);
    }
    return mx;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(h[i]);
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int root = 0;
    for (int i = 1; i <= n; ++i) {
        if (h[i] > h[root]) {
            root = i;
        }
    }
    DFS(root, 0);
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}