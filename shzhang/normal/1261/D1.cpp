#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <set>
#include <queue>

using namespace std;

#define ll long long

#define MOD 998244353
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)

int f[2005][4005];
int a[2005];
int k, n;

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    a[n+1] = a[1];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n * 2; j++) {
            if (a[i] != a[i+1]) {
                if (j >= 1) f[i][j] += mul(k-2, f[i-1][j-1]); /* choose neither */
                if (f[i][j] >= MOD) f[i][j] -= MOD;
                if (j >= 2) f[i][j] += f[i-1][j-2]; /* choose new ans */
                if (f[i][j] >= MOD) f[i][j] -= MOD;
                f[i][j] += f[i-1][j];
                if (f[i][j] >= MOD) f[i][j] -= MOD;
            } else {
                if (j >= 1) f[i][j] += mul(k, f[i-1][j-1]);
                if (f[i][j] >= MOD) f[i][j] -= MOD;
            }
            //printf("%d %d %d\n", i, j, f[i][j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += f[n][i];
        if (ans >= MOD) ans -= MOD;
    }
    printf("%d", ans);
    return 0;
}