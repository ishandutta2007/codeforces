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

mi f[2000005];
mi fact[4000005];
mi ifact[4000005];

mi ssum[2000005];

mi C(int x, int y)
{
    //printf("C: %d %d\n", x, y);
    return fact[x] * ifact[y] * ifact[x-y];
}

int n, m;

int main()
{
    fact[0] = 1_m;
    for (int i = 1; i <= 4000000; i++) fact[i] = fact[i-1] * (mi)i;
    ifact[4000000] = 1_m / fact[4000000];
    for (int i = 3999999; i >= 0; i--) ifact[i] = ifact[i+1] * (mi)(i + 1);

    scanf("%d%d", &n, &m);
    mi minus_i_val = 0;
    for (int i = m; i <= n + m; i++) {
        minus_i_val = minus_i_val + fact[i-1] * fact[n+m-i] * (mi)i * C(n, n + m - i);
    }
    for (int x = n - 1; x >= 0; x--) {
        mi self_coeff = ifact[n-x] * fact[m+n-x-1];
        mi other = 0_m - minus_i_val * ifact[n-x] * ifact[n + m] * fact[n + m - x];
        //for (int j = 1; j <= n - x; j++) {
        //    mi val = ifact[n-x-j] * fact[m+n-x-j-1];
        //    other = other + val * f[x + j];
        //}
        other = other + ssum[x+1];
        self_coeff = self_coeff * (mi)m * ifact[n+m] * fact[x] * fact[n-x] * C(n + m, n + m - x);
        other = other * (mi)m * ifact[n+m] * fact[x] * fact[n-x] * C(n + m, n + m - x);
        other = other + (mi)(n + m + 1);

        f[x] = other / (1_m - self_coeff);
        ssum[x] = ssum[x+1] + ifact[n-x] * fact[m+n-x-1] * f[x];
    }
    printf("%d", f[0].val);
    return 0;
}