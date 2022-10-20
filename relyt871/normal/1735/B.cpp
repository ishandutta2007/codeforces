#include <bits/stdc++.h>
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

int n, a[MAXN];

void solve() {
    read(n);
    int mn = 1e9;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        mn = min(mn, a[i]);
    }
    LL ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += a[i] / (mn * 2 - 1);
        if (a[i] % (mn * 2 - 1) == 0) --ans;
    }
    printf("%lld\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}