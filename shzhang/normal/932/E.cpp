#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long
#define MOD 1000000007
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

int f[5005][5005];

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    f[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= min(i, n); j++) {
            f[i][j] = mul(j, f[i-1][j]) + mul(n-j+1, f[i-1][j-1]);
            if (f[i][j] >= MOD) f[i][j] -= MOD;
        }
    }
    int ans = 0;
    for (int i = 1; i <= min(k, n); i++) {
        //printf("%d ", f[k][i]);
        ans += mul(f[k][i], fpow(2, n-i));
        ans %= MOD;
    }
    printf("%d", ans);
    return 0;
}