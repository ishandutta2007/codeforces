#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n, m, k;
int f[5005][5005];

int fpow(int base, int exponent)
{
    int Ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1) Ans = mul(Ans, cur);
        cur = mul(cur, cur); exponent >>= 1;
    }
    return Ans;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= min(i, n); j++) {
            f[i][j] = mul(j, f[i-1][j]) + mul(n-j+1, f[i-1][j-1]);
            if (f[i][j] >= MOD) f[i][j] -= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= min(k, n); i++) {
        ans += mul(f[k][i], fpow(m, n-i));
        if (ans >= MOD) ans -= MOD;
    }
    ans = mul(ans, fpow(fpow(m, n), MOD-2));
    printf("%d", ans);
    return 0;
}