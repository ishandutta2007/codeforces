#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdlib>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

#define ll long long

#ifndef ONLINE_JUDGE
#define debug(format, ...) fprintf(stderr, \
    "%s:%d: " format "\n", __func__, __LINE__,##__VA_ARGS__)
#else
#define debug(format, ...)
#define NDEBUG
#endif

template<int mod, class itype> struct ModInt {
    int val;
    ModInt() {
        val = 0;
    }
    ModInt(int a) {
        val = a % mod;
    }
};

#define DEFMOD(mod, type) typedef ModInt<mod, int> type;     \
                          type operator "" _m(unsigned long long x) {   \
                              type res = x; return res; \
                          }

DEFMOD(1000000007, mi)

template<int mod, class itype> ModInt<mod, itype> fpow(ModInt<mod, itype> base, int exponent)
{
    ModInt<mod, itype> ans = 1_m;
    ModInt<mod, itype> cur = base;
    while (exponent) {
        if (exponent & 1) ans = ans * cur;
        cur = cur * cur; exponent >>= 1;
    }
    return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator+(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ll val = (ll)(a.val) + (ll)(b.val);
    if (val >= mod) val -= mod;
    ans.val = val; return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator-(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ans.val = a.val - b.val;
    if (ans.val < 0) ans.val += mod;
    return ans;
}

template<int mod, class itype> ModInt<mod, itype> operator*(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
    ModInt<mod, itype> ans;
    ans.val = ((ll)(a.val) * (ll)(b.val)) % (ll)mod;
    return ans;
}

// PRIME MOD ONLY!
template<int mod, class itype> ModInt<mod, itype> operator/(ModInt<mod, itype> a, ModInt<mod, itype> b)
{
#ifndef ONLINE_JUDGE
    if (b.val == 0) {
        fprintf(stderr, "Division by zero :(\n"); abort();
    }
#endif
    return a * fpow(b, mod - 2);
}

/* dig, current digit, # >= dig, is_equal */
mi f[11][705][705][2];

char x[705];

mi a[10][705];

int main()
{
    scanf("%s", x + 1);
    int n = strlen(x + 1);
    for (int dig = 1; dig <= 10; dig++) {
        f[dig][0][0][1] = 1_m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                for (int nxt = 0; nxt <= 9; nxt++) {
                    mi& nxt_0 = f[dig][i+1][j + (nxt >= dig ? 1 : 0)][0];
                    mi& nxt_1 = f[dig][i+1][j + (nxt >= dig ? 1 : 0)][1];
                    nxt_0 = nxt_0 + f[dig][i][j][0];
                    if (nxt < x[i+1] - '0') nxt_0 = nxt_0 + f[dig][i][j][1];
                    if (nxt == x[i+1] - '0') nxt_1 = nxt_1 + f[dig][i][j][1];
                }
            }
        }
    }
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k <= j; k++) {
                a[i][j] = a[i][j] + f[i+1][n][k][0] + f[i+1][n][k][1];
            }
            for (int k = 0; k < i; k++) a[i][j] = a[i][j] - a[k][j];
        }
    }
    mi ans = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < n; j++) {
            //debug("a[%d][%d] = %d\n", i, j, a[i][j].val);
            ans = ans + a[i][j] * fpow(10_m, j) * (mi)i;
        }
    }
    printf("%d", ans.val);
    return 0;
}