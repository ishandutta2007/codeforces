#include <bits/stdc++.h>
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

namespace ModCalculator {
    const int MOD = 1e9 + 7;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline void Dec(int &x, int y) {
        x -= y; if (x < 0) x += MOD;
    }
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
    inline int Sub(int x, int y) {
        Dec(x, y); return x;
    }
    inline int Mul(int x, int y) {
        return 1LL * x * y % MOD;
    }
    inline int Ksm(int x, int y) {
        int ret = 1;
        for (; y; y >>= 1) {
            if (y & 1) ret = Mul(ret, x);
            x = Mul(x, x);
        }
        return ret;
    }
    inline int Inv(int x) {
        return Ksm(x, MOD - 2);
    }
}
using namespace ModCalculator;

int n, v2, pw[MAXN], ans[MAXN];

void solve() {
    read(n);
    int suf = 0;
    for (int i = n, j = n; i >= 1; --i) {
        int cur = pw[(i - 1) / 2];
        if (i < n) cur = Mul(cur, v2);
        while (j >= i * 2) {
            Inc(suf, ans[j--]);
        }
        ans[i] = Mul(cur, Sub(1, suf));
    }
    ans[1] = (n == 1);
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", ans[i]);
    }
}

int main() {
    v2 = Inv(2);
    pw[0] = 1;
    for (int i = 1; i < MAXN; ++i) {
        pw[i] = Mul(pw[i - 1], v2);
    }
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}