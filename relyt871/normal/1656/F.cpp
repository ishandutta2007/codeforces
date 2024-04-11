#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
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

int n;
LL a[MAXN];

void solve() {
    read(n);
    LL sum = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        sum += a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[n] * (n - 2) + sum < 0 || a[1] * (n - 2) + sum > 0) {
        puts("INF");
        return;
    }
    LL cur = -a[n] * a[n] * (n - 1), ans = cur;
    LL delta = a[n] * (n - 2) + sum;
    for (int i = n - 1; i >= 1; --i) {
        cur += (a[i + 1] - a[i]) * delta;
        ans = max(ans, cur);
        delta += a[1] - a[n];
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