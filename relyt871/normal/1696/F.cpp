#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 105;

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

char s[N];
int n, dep[N];
bool same[N][N][N], vis[N];
vector<int> tree[N];

bool DFS1(int u, int fa) {
    vis[u] = 1;
    tree[u].push_back(fa);
    tree[fa].push_back(u);
    for (int v = 2; v <= n; ++v) {
        if (v == fa) continue;
        if (same[v][fa][u]) {
            if (vis[v]) {
                return 0;
            }
            if (!DFS1(v, u)) {
                return 0;
            }
        }
    }
    return 1;
}

void DFS2(int u, int fa) {
    dep[u] = dep[fa] + 1;
    for (auto v : tree[u]) {
        if (v == fa) continue;
        DFS2(v, u);
    }
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            same[i][i][j] = 1;
        }
        for (int j = i + 1; j <= n; ++j) {
            scanf("%s", s + 1);
            for (int k = 1; k <= n; ++k) {
                same[j][i][k] = same[i][j][k] = (s[k] == '1');
            }
        }
    }
    for (int v = 2; v <= n; ++v) {
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
            vis[i] = 0;
        }
        bool flag = 1;
        vis[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (same[i][v][1]) {
                if (vis[i]) {
                    flag = 0; break;
                }
                if (!DFS1(i, 1)) {
                    flag = 0; break;
                }
            }
        }
        if (!flag) continue;
        for (int i = 1; i <= n; ++i) {
            if (!vis[i]) flag = 0;
        }
        for (int i = 1; i <= n && flag; ++i) {
            DFS2(i, 0);
            for (int j = 1; j <= n && flag; ++j) {
                for (int k = 1; k <= n && flag; ++k) {
                    if (same[j][k][i] != (dep[j] == dep[k])) {
                        flag = 0;
                    }
                }
            }
        }
        if (flag) {
            puts("Yes");
            for (int i = 1; i <= n; ++i) {
                for (auto j : tree[i]) {
                    if (j > i) printf("%d %d\n", i, j);
                }
            }
            return;
        }
    }
    puts("No");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}