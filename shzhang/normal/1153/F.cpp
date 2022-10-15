#include <cstdio>
#include <algorithm>
//
using namespace std;

#define ll long long
#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int n, k, l;

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

int C[4005][4005];

int gpwrs[4005];
int g[4005][4005];
int f[4005];

int main()
{
    scanf("%d%d%d", &n, &k, &l);
    C[0][0] = 1;
    for (int i = 1; i <= 4003; i++) {
        for (int j = 0; j <= i; j++) {
            C[i][j] = C[i-1][j] + (j == 0 ? 0 : C[i-1][j-1]);
            if (C[i][j] >= MOD) C[i][j] -= MOD;
        }
    }
    l %= MOD;
    for (int x = k; x <= n; x++) {
        for (int y = 0; y <= n-x; y++) {
            gpwrs[x+y] += mul(C[n][x], mul(C[n-x][y], y % 2 ? MOD-1 : 1));
            if (gpwrs[x+y] >= MOD) gpwrs[x+y] -= MOD;
        }
    }
    g[0][0] = 1;
    for (int i = 0; i < 4000; i++) {
        for (int j = 0; j <= 4003; j++) {
            g[i+1][j+1] += mul(2, g[i][j]);
            if (g[i+1][j+1] >= MOD) g[i+1][j+1] -= MOD;
            g[i+1][j+2] -= mul(2, g[i][j]);
            g[i+1][j+2] %= MOD; g[i+1][j+2] += MOD; g[i+1][j+2] %= MOD;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 4003; j++) {
            f[j] += mul(g[i][j], gpwrs[i]);
            if (f[j] >= MOD) f[j] -= MOD;
        }
    }
    //for (int i = 0; i <= 10; i++) printf("%d ", g[1][i]);
    for (int i = 4003; i >= 0; i--) {
        f[i+1] = mul(f[i], fpow(i+1, MOD-2));
    }
    int ans = 0;
    for (int i = 1; i <= 4004; i++) {
        ans += f[i];
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d", (int)mul(ans, l));
    return 0;
}