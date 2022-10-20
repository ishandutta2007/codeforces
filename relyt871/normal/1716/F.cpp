#include<bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;
const int N = 2005;

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
    const int MOD = 998244353;
    inline void Inc(int &x, int y) {
        x += y; if (x >= MOD) x -= MOD;
    }
    inline int Add(int x, int y) {
        Inc(x, y); return x;
    }
    inline void Dec(int &x, int y) {
        x -= y; if (x < 0) x += MOD;
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

int n, m, k, stir[N][N];

void solve() {
    read(n); read(m); read(k);
    if (m == 1) {
        printf("%d\n", Ksm(n, k));
        return;
    }
    int x = (m + 1) / 2, y = m / 2;
    x = Mul(x, Inv(y));
    int vx = Inv(x + 1);
    int ans = 0, v1 = 1, v2 = 1, v3 = Ksm(x + 1, n);
    for (int i = 0; i <= k; ++i) {
        Inc(ans, Mul(stir[k][i], Mul(v1, Mul(v2, v3))));
        v1 = Mul(v1, n - i);
        v2 = Mul(v2, x);
        v3 = Mul(v3, vx);
    }
    printf("%d\n", Mul(ans, Ksm(y, n)));
}

int main() {
    n = 2000;
    stir[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            stir[i][j] = Add(stir[i - 1][j - 1], Mul(stir[i - 1][j], j));
        }
    }
    int T; read(T);
    while (T--) {
        solve();
    }
    return 0;
}