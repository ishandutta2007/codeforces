#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
using namespace std;
typedef long long LL;
const int MAXN = 500005;
const int INF = 0x3f3f3f3f;

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

template <typename T> inline void cmin(T &x, T y) {
    if (x > y) x = y;
}

template <typename T> inline void cmax(T &x, T y) {
    if (x < y) x = y;
}

int n, a[MAXN], pos, ans;
int f[MAXN], g[MAXN], h[2][MAXN];

void Work() {
    f[1] = -1;
    for (int i = 2; i <= pos; ++i) {
        f[i] = INF;
        if (a[i - 1] < a[i]) {
            cmin(f[i], f[i - 1]);
        }
        if (f[i - 1] < a[i]) {
            cmin(f[i], a[i - 1]);
        }
    }
    g[n] = -1;
    for (int i = n - 1; i >= pos; --i) {
        g[i] = INF;
        if (a[i + 1] < a[i]) {
            cmin(g[i], g[i + 1]);
        }
        if (g[i + 1] < a[i]) {
            cmin(g[i], a[i + 1]);
        }
    }
    h[0][pos] = f[pos];
    h[1][pos] = -INF;
    for (int i = pos + 1; i <= n; ++i) {
        h[0][i] = INF;
        if (a[i - 1] > a[i]) {
            cmin(h[0][i], h[0][i - 1]);
        }
        if (h[1][i - 1] > a[i]) {
            cmin(h[0][i], a[i - 1]);
        }
        h[1][i] = -INF;
        if (a[i - 1] < a[i]) {
            cmax(h[1][i], h[1][i - 1]);
        }
        if (h[0][i - 1] < a[i]) {
            cmax(h[1][i], a[i - 1]);
        }
        ans+= (h[1][i] > g[i]);
    }
}

void solve() {
    read(n);
    pos = 0;
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        if (a[i] > a[pos]) {
            pos = i;
        }
    }
    Work();
    reverse(a + 1, a + n + 1);
    pos = n - pos + 1;
    Work();
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}