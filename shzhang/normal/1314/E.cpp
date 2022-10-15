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

// TEMPLATE STARTS BELOW

#define DEFMOD(mod, type) typedef ModInt<mod, int> type;     \
                          type operator "" _m(unsigned long long x) {   \
                              type res = x; return res; \
                          }

template<int mod, class itype> struct ModInt {
    int val;
    ModInt() {
        val = 0;
    }
    ModInt(int a) {
        val = a % mod;
    }
};

/* MODIFY AS NEEDED */

DEFMOD(998244353, mi)

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

int n, K;

mi f1[2500][2500];
mi* f[80][2500];

int xans = 0;

int seq[105];
int tmp[105];

int* vals; int* nvals;
int vals_cur = 0; int nvals_cur = 0;

void dfs(int idx, int val, int remain)
{
    seq[idx] = val;

    for (int i = idx; i >= 1; i--) vals[idx - i] = seq[i];
    vals_cur = idx; nvals_cur = 0;
    bool good = true;
    for (int it = 1; it < K; it++) {
        int s = 0;
        for (int i = 0; i < vals_cur; i++) {
            for (int j = 1; j <= vals[i]; j++) {
                nvals[nvals_cur++] = vals_cur - i;
            }
            s += vals[i] * (vals_cur - i);
            if (s > n) {
                good = false; goto loop_end;
            }
        }
        swap(vals, nvals); swap(vals_cur, nvals_cur);
        reverse(vals, vals + vals_cur);
        nvals_cur = 0;
    }
loop_end:
    if (!good) {
        return;
    } else {
        xans++;
    }

    for (int nxt = 1; nxt <= min(val, remain); nxt++) {
        dfs(idx + 1, nxt, remain - nxt);
    }
}

int main()
{
    scanf("%d%d", &n, &K);
    if (K == 1) {
        f1[0][0] = 1_m;
        mi ans = 0_m;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                f1[i][j] = f1[i][j-1] + (j <= i ? f1[i-j][j] : 0_m);
            }
            if (i) ans = ans + f1[i][i];
        }
        printf("%d", ans.val);
    } else if (K == 2) {
        mi ans = 0_m;
        for (int i = 0; i <= 70; i++) {
            for (int j = 1; j <= n && i * j <= n; j++) {
                f[i][j] = new mi[n + 5];
            }
        }
        for (int i = 1; i <= n; i++) {
            f[0][i][0] = 1_m;
        }
        for (int i = 1; i <= 70; i++) {
            for (int j = n / i; j >= 1; j--) {
                for (int k = i * j; k <= n; k++) {
                    f[i][j][k] = (i * (j + 1) <= k ? f[i][j+1][k] : 0_m) +
                        ((i - 1) * j <= k - i * j ? f[i-1][j][k - i * j] : 0_m);
                }
            }
        }
        for (int i = 1; i <= 70; i++) {
            for (int k = i; k <= n; k++) {
                ans = ans + f[i][1][k];
            }
        }
        printf("%d", ans.val);
    } else {
        vals = new int[100005];
        nvals = new int[100005];
        for (int i = 1; i <= (K >= 4 ? 21 : 63); i++) {
            dfs(1, i, (K >= 4 ? 21 : 63));
        }
        printf("%d", xans);
    }
    return 0;
}