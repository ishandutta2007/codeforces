#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
int p, alpha, a[2003], len;
char A[2003];

int M(int x) { return x >= mod ? x - mod : x; }

struct Big_based_p {
    int len, x[4003];
    void init() {
        while (::len) {
            long long t = 0;
            for (int i = ::len; i >= 1; --i) {
                t = t * 10 + a[i], a[i] = t / p, t %= p;
                if (!a[i] && i == ::len) --::len;
            }
            x[++len] = t;
        }
    }
    int f[3503][3503][2][2];
    void work() {
        f[len + 1][0][0][1] = 1;
        for (int i = len, c1, c2, c3, c4, c5, c6; i >= 1; --i) {
            c1 = 1ll * (p + 1) * p / 2 % mod,
            c2 = 1ll * (x[i] + 1) * x[i] / 2 % mod,
            c3 = 1ll * p * (p - 1) / 2 % mod,
            c4 = 1ll * x[i] * ((p << 1) - x[i] - 1) / 2 % mod,
            c5 = 1ll * x[i] * (x[i] - 1) / 2 % mod,
            c6 = 1ll * x[i] * ((p << 1) - x[i] + 1) / 2 % mod;

            for (int j = 0, f0, f1, f2, f3; j <= len - i + 1; ++j) {
                f0 = f[i + 1][j][0][0], f1 = f[i + 1][j][0][1],
                f2 = f[i + 1][j][1][0], f3 = f[i + 1][j][1][1];
                if (!f0 && !f1 && !f2 && !f3) continue;
                f[i][j][0][0] = (1ll * c1 * f0 % mod + 1ll * c2 * f1 % mod +
                                 1ll * c3 * f2 % mod + 1ll * c4 * f3 % mod) %
                                mod;
                f[i][j][0][1] = M(1ll * (x[i] + 1) * f1 % mod +
                                  1ll * (p - x[i] - 1) * f3 % mod);
                f[i][j + 1][1][0] =
                    (1ll * c3 * f0 % mod + 1ll * c5 * f1 % mod +
                     1ll * c1 * f2 % mod + 1ll * c6 * f3 % mod) %
                    mod;
                f[i][j + 1][1][1] =
                    M(1ll * x[i] * f1 % mod + 1ll * (p - x[i]) * f3 % mod);
            }
        }
        int res = 0;
        for (int i = alpha; i <= len; ++i)
            res = M(res + M(f[1][i][0][0] + f[1][i][0][1]));
        printf("%d\n", res);
    }
} lim;

int main() {
    scanf("%d%d%s", &p, &alpha, A + 1), len = strlen(A + 1);
    if (alpha > 4000) return puts("0"), 0;
    for (int i = 1; i <= len; ++i) a[i] = A[len - i + 1] - '0';
    lim.init(), lim.work();
    return 0;
}