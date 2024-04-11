#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <cstdlib>

using namespace std;

char s[5005];

typedef int I;
#define ll long long
#define MOD 1000000007
#define rep(var, to) for (I var = 1; var <= (to); var++)
#define repv(vec, var) for (I var = 0; var < (vec).size(); var++)
#define repf(var, from, to) for (I var = (from); var <= (to); var++)
#define repd(var, from, to) for (I var = (from); var >= (to); var--)
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int fpow(int base, int exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return ans;
}

struct Matrix {
    int val[3][3];
};

Matrix mulmatrix(Matrix a, Matrix b)
{
    Matrix ans;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            ans.val[i][j] = mul(a.val[i][1], b.val[1][j]) +
                             mul(a.val[i][2], b.val[2][j]);
            ans.val[i][j] %= MOD;
        }
    }
    return ans;
}

Matrix matpow(Matrix a, ll power)
{
    Matrix ans;
    ans.val[1][1] = ans.val[2][2] = 1;
    ans.val[1][2] = ans.val[2][1] = 0;
    Matrix cur = a;
    while (power) {
        if (power & 1LL) ans = mulmatrix(ans, cur);
        cur = mulmatrix(cur, cur); power >>= 1LL;
    }
    return ans;
}

int main()
{
    int k;
    scanf("%d", &k);
    Matrix base;
    base.val[1][1] = 0;
    base.val[1][2] = 2;
    base.val[2][1] = base.val[2][2] = 1;
    ll prod = 1;
    for (int i = 1; i <= k; i++) {
        ll val;
        scanf("%lld", &val);
        base = matpow(base, val);
        prod *= (val % (MOD-1));
        prod %= MOD-1;
    }
    printf("%d/%d", (int)(mul(base.val[1][1], fpow(2, MOD-2))), fpow(2, ((prod-1) % (MOD-1) + (MOD-1)) % (MOD-1)));
    return 0;
}