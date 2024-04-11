#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define MP make_pair
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int MAXN = 300005;

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

int n, f[MAXN];
vector<int> tree[MAXN];

int DFS(int u, int fa, int d) {
    int mx = d, mx2 = d;
    for (auto v : tree[u]) {
        if (v == fa) continue;
        int tmp = DFS(v, u, d + 1);
        if (tmp > mx) {
            mx2 = mx;
            mx = tmp;
        } else if (tmp > mx2) {
            mx2 = tmp;
        }
    }
    int x = min(mx, mx2) - 1;
    if (x >= 0) {
        f[x] = max(f[x], mx + mx2 - d * 2);
    }
    return mx;
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        f[i] = 0;
        tree[i].clear();
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u); read(v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int mxd = DFS(1, 0, 0);
    for (int i = n - 1; i >= 0; --i) {
        f[i] = max(f[i], f[i + 1]);
    }

    int ans = 0;
    for (int x = 1; x <= n; ++x) {
        while (ans < mxd && (f[ans] + 1) / 2 + x > ans) {
            ++ans;
        }
        printf("%d ", ans);
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