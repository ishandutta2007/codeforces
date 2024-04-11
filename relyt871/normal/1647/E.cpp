#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 100005;

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

int n, a[MAXN], deg[MAXN], vis[MAXN], remo, mx, rd, to[MAXN][32];
set<int> S;

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(to[i][0]);
        ++deg[to[i][0]];
    }
    for (int i = 1; i <= 31; ++i) {
        for (int u = 1; u <= n; ++u) {
            to[u][i] = to[to[u][i - 1]][i - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        mx = max(mx, a[i]);
        if (a[i] <= n) {
            vis[a[i]] = 1;
        }
        remo += (deg[i] == 0);
    }
    rd = (mx - n) / remo;

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            S.insert(i);
        }
    }
    mset(vis, 0);
    for (int i = 1, ans; i <= n; ++i) {
        int des = i;
        for (int i = 31; i >= 0; --i) {
            if ((rd >> i) & 1) {
                des = to[des][i];
            }
        }
        if (!vis[des]) {
            ans = a[des];
            vis[des] = 1;
        } else {
            ans = *S.lower_bound(a[des]);
            S.erase(ans);
        }
        printf("%d ", ans);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}