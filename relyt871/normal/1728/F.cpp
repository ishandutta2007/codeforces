#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1005;
const int MAXN = 1000006;

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

int n, a[N], m, w[MAXN];
vector<int> g[MAXN];
int vis[N], tim, mtch[N];

bool Match(int u) {
    for (auto v : g[u]) {
        if (vis[v] == tim) continue;
        vis[v] = tim;
        if (!mtch[v] || Match(mtch[v])) {
            mtch[v] = u;
            return 1;
        }
    }
    return 0;
}


void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        for (int j = 1; j <= n; ++j) {
            w[++m] = a[i] * j;
        }
    }
    sort(w + 1, w + m + 1);
    m = unique(w + 1, w + m + 1) - (w + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[lower_bound(w + 1, w + m + 1, a[i] * j) - w].push_back(i);
        }
    }
    LL ans = 0;
    tim = 1;
    for (int i = 1; i <= m; ++i) {
        if (Match(i)) {
            ans += w[i];
            ++tim;
        }
    }
    printf("%lld\n", ans);
}

int main() {
    solve();
    return 0;
}