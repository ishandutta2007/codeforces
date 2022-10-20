#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 5005;

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
    int MOD;
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

int n, fac[N], finv[N], C[N][N], pw[N][N];

void solve() {
    read(n); read(MOD);
    fac[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fac[i] = Mul(fac[i - 1], i);
    }
    finv[n] = Inv(fac[n]);
    for (int i = n; i >= 1; --i) {
        finv[i - 1] = Mul(finv[i], i);
    }
    for (int i = 0; i <= n; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }
        pw[i][0] = 1;
        for (int j = 1; j <= n; ++j) {
            pw[i][j] = Mul(pw[i][j - 1], i);
        }
    }
    int ans = 0, tmp = 1;
    for (int i = 1; i * 2 <= n; ++i) {
        tmp = Mul(tmp, n - 1);
        for (int j = 0; j <= n - i * 2; ++j) {
            int v1 = Mul(C[n][j], Mul(tmp, pw[n - i - j][j]));
            int v2 = Mul(Mul(fac[n - j], C[n - i - j - 1][i - 1]), finv[i]);
            Inc(ans, Mul(v1, v2));
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}