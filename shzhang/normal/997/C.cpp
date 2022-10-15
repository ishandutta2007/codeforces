#include <cstdio>
//
using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, ll exponent)
{
    if (exponent < 0) {
        return fpow(fpow(base, -exponent), MOD - 2);
    }
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1LL) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1LL;
    }
    return ans;
}

ll n;

/*int gsum(int base, ll exponent)
{
    if (exponent < 0) exponent = 0;
    if (base == 0) return 0;
    if (base == 1) return exponent + 1;
    return mul(fpow(base, exponent + 1) + MOD - 1, fpow(base - 1, MOD - 2));
}*/

int factorial[1000005];
int factorial_inv[1000005];

int C(int a, int b)
{
    return mul(factorial[a], mul(factorial_inv[b], factorial_inv[a-b]));
}

int main()
{
    factorial[0] = 1;
    for (int i = 1; i <= 1000000; i++) {
        factorial[i] = mul(i, factorial[i-1]);
    }
    factorial_inv[1000000] = fpow(factorial[1000000], MOD - 2);
    for (int i = 999999; i >= 0; i--) {
        factorial_inv[i] = mul(factorial_inv[i + 1], i + 1);
    }
    //printf("%d\n", factorial_inv[0]);
    scanf("%lld", &n);
    /*int ans2 = 0;
    for (ll a = 1; a <= n; a++) {
        for (ll b = 1; b <= n; b++) {
            //if (a != 0 || b != 0) {
                ans2 += mul(mul(C(n, a), C(n, b)), mul((((a + b + 1) & 1) ? MOD - 1 : 1), fpow(3, (n - a) * (n - b))));
                ans2 %= MOD;
            //}
        }
    }
    ans2 = mul(ans2, 3);
    printf("%d\n", ans2);*/
    int ans = 0;
    for (ll a = 1; a <= n; a++) {
        int x = MOD - fpow(3, a - n);
        x++; if (x == MOD) x = 0;
        ans += mul(C(n, a), mul(fpow(3, -(a*n)), mul(((a + 1) & 1 ? MOD - 1 : 1), fpow(x, n) + MOD - 1)));
        if (ans >= MOD) ans -= MOD;
    }
    ans = mul(ans, fpow(3, n * n + 1LL));
    //printf("%d\n", ans);
    int cnt = 0;
    for (ll a = 1; a <= n; a++) {
        cnt += mul(C(n, a), mul(((a + 1) & 1 ? MOD - 1 : 1), fpow(3, n * n - (n-1) * a)));
        if (cnt >= MOD) cnt -= MOD;
    }
    ans = (ans + mul(cnt, 2)) % MOD;
    printf("%d", ans);
    return 0;
}