#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 1005;

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

int n, n1, n2;
LL a[N], b[N], m;
vector<int> g[N];
int vis[N], tim, matchl[N], matchr[N];

int Match(int u) {
    for (auto v : g[u]) {
        if (vis[v] == tim) continue;
        vis[v] = tim;
        if (!matchr[v] || Match(matchr[v])) {
            matchl[u] = v;
            matchr[v] = u;
            return 1;
        }
    }
    return 0;
}

void solve() {
    read(n); read(m);
    for (int i = 1; i <= n; ++i) {
        LL x; read(x);
        if (x > m / 3) {
            a[++n1] = x;
        } else {
            b[++n2] = x;
        }
    }
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (a[i] % b[j] == 0 && a[i] * 2 + b[j] <= m) {
                g[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= n1; ++i) {
        ++tim;
        if (!Match(i)) {
            puts("-1");
            return;
        }
    }
    printf("%d\n", n2);
    for (int i = 1; i <= n2; ++i) {
        int j = matchr[i];
        if (j) {
            printf("%lld %lld\n", a[j] * 2 + b[i], a[j] + b[i]);
        } else {
            printf("%lld %lld\n", b[i] * 3, b[i] * 2);
        }
    }
}

int main() {
    solve();
    return 0;
}