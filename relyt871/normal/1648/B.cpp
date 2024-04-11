#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int MAXN = 1000005;

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

int n, C, a[MAXN], vis[MAXN], cov[MAXN];

inline void Cover(int l, int r) {
    ++cov[l];
    if (r + 1 <= C) --cov[r + 1];
}

void solve() {
    read(n); read(C);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - (a + 1);
    if (a[1] != 1) {
        puts("No");
        return;
    }
    for (int i = 1; i <= C; ++i) {
        cov[i] = 0;
        vis[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        vis[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        int x = a[i];
        for (int j = 1; x * j <= C; ++j) {
            if (!vis[j]) continue;
            Cover(x * j, x * (j + 1) - 1);
        }
    }
    for (int i = 1; i <= C; ++i) {
        cov[i] += cov[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        if (cov[a[i]] != i) {
            puts("No");
            return;
        }
    }
    puts("Yes");
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}