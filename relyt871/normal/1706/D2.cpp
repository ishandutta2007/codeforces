#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
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

int n, k, nxt[MAXN];

void solve() {
    read(n); read(k);
    for (int i = 1; i < MAXN; ++i) {
        nxt[i] = 0;
    }
    int mn = MAXN, mx = 0;
    for (int t = 1; t <= n; ++t) {
        int x; read(x);
        mn = min(mn, x);
        mx = max(mx, x);
        int lst = 0x3f3f3f3f;
        for (int i = 1, j; i <= x && i <= k; i = j + 1) {
            j = x / (x / i);
            int y = x / i;
            nxt[y + 1] = max(nxt[y + 1], lst);
            lst = y;
        }
        nxt[1] = max(nxt[1], lst);
    }
    int far = 0, ans = mx / k - mn / k;
    for (int i = 1; i <= mn; ++i) {
        far = max(far, nxt[i]);
        ans = min(ans, far - i);
    }
    printf("%d\n", ans);
}

int main() {
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}