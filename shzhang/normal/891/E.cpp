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
        val = ((a % mod) + mod) % mod;
    }
};

/* MODIFY AS NEEDED */

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

int n, k;
//mi f[5005][5005];
mi a[5005];

mi fact[5005];
mi ifact[5005];

mi poly[5005];
mi tmp[5005];
mi anspoly[5005];

mi inv_p5000[10005];

int main()
{
    scanf("%d%d", &n, &k);
    fact[0] = 1_m;
    for (int i = 1; i <= 5000; i++) {
        fact[i] = (mi)i * fact[i-1];
    }
    for (int i = 0; i <= 5000; i++) {
        ifact[i] = 1_m / fact[i];
    }
    mi prod = 1_m;
    for (int i = 1; i <= n; i++) {
        int x; scanf("%d", &x);
        a[i] = x; prod = prod * a[i];
    }
    for (int i = -5000; i <= 5000; i++) {
        if (!i) continue;
        inv_p5000[i + 5000] = 1_m / (mi)i;
        //if (i >= 1 && i <= 10) printf("%d ", inv_p5000[i + 5000].val);
    }
    /*for (int i = 0; i <= k; i++) {
        f[1][i] = (a[1] - (mi)i) * ifact[i];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int cnt = 0; cnt <= j; cnt++) {
                f[i][j] = f[i][j] + (((a[i] - (mi)cnt) * f[i-1][j-cnt])) / fact[cnt];
            }
            //f[i][j] = f[i][j] / fpow((mi)i, j);
            printf("f[%d][%d] = %d\n", i, j, (f[i][j] * fact[j] / fpow((mi)i, j)).val);
        }
    }*/
    poly[0] = 1_m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) tmp[j] = poly[j];
        for (int j = n; j > 0; j--) poly[j] = 0_m - poly[j-1];
        poly[0] = 0_m;
        for (int j = 0; j <= n; j++) poly[j] = poly[j] + a[i] * tmp[j];
    }
    mi curpwr = 1;
    for (int i = 0; i <= n; i++) {
        tmp[i] = curpwr * ifact[i];
        curpwr = curpwr * (mi)n;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; i + j <= n; j++) {
            anspoly[i+j] = anspoly[i+j] + poly[i] * tmp[j];
        }
    }
    for (int i = 0; i <= n; i++) anspoly[i] = anspoly[i] * fact[i] / fpow((mi)n, i);
    mi ans = 0;
    for (int i = 0; i <= n; i++) {
        //printf("%d ", anspoly[i].val);
        mi pro = 1;
        for (int j = 0; j <= n; j++) {
            if (j == i) continue;
            pro = pro * ((mi)(k - j) * inv_p5000[i - j + 5000]);
        }
        ans = ans + pro * anspoly[i];
    }
    printf("%d", (prod - ans).val);
    return 0;
}