#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;
typedef long long LL;
const int N = 255;
const int M = 62505;

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

int n, k;
int C[N][N], dp[N][N], pw[N][M];

void solve() {
    for (int i = 0; i < N; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = Add(C[i - 1][j], C[i - 1][j - 1]);
        }
        pw[i][0] = 1;
        for (int j = 1; j < M; ++j) {
            pw[i][j] = Mul(pw[i][j - 1], i);
        }
    }
    read(n); read(k);
    dp[0][0] = 1;
    for (int i = 1; i <= k; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int x = 0; x <= j; ++x) {
                Inc(dp[i][j], Mul(dp[i - 1][x], Mul(C[j][x], pw[k - i + 1][C[j][2] - C[x][2]])));
            }
        }
    }
    printf("%d\n", dp[k][n - 1]);
}

int main() {
    solve();
    return 0;
}