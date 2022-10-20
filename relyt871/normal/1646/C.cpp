#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
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

int tot, cnt[MAXN];
LL fac[20], sum[MAXN];

void DFS(int p, int c, LL s) {
    if (p > 14) {
        cnt[++tot] = c;
        sum[tot] = s;
        return;
    }
    DFS(p + 1, c, s);
    DFS(p + 1, c + 1, s + fac[p]);
}

void prework() {
    fac[0] = 1;
    for (int i = 1; i <= 14; ++i) {
        fac[i] = fac[i - 1] * i;
    }
    DFS(1, 0, 0);
}

inline int popcount(LL x) {
    LL ret = 0;
    while (x) {
        ret += (x & 1);
        x >>= 1;
    }
    return ret;
}

void solve() {
    LL n; read(n);
    int ans = 10000000;
    for (int i = 1; i <= tot; ++i) {
        if (sum[i] <= n) {
            ans = min(ans, cnt[i] + popcount(n - sum[i]));
        }
    }
    printf("%d\n", ans);
}

int main() {
    prework();
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}