#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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

int n, a[MAXN], ans[MAXN], m, b[MAXN];
set<int> S;

inline bool cmp(int x, int y) {
    return a[x - 1] - a[x] < a[y - 1] - a[y];
}

void solve() {
    read(n);
    S.clear();
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        S.insert(i);
        ans[i] = 1;
    }
    m = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] < a[i - 1]) {
            b[++m] = i;
        }
    }
    sort(b + 1, b + m + 1, cmp);
    for (int i = m; i >= 1; --i) {
        auto it = S.lower_bound(a[b[i] - 1] - a[b[i]]);
        ans[*it] = b[i];
        S.erase(it);
    }
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