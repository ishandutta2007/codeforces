#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int factorial[255];
#define ll long long
#define MOD 1000000007
#define mul(a, b) (((ll)(a) * (ll)(b)) % MOD)
int f[255][255];
int s[255][255];

int fpow(int base, ll exponent)
{
    int ans = 1;
    int cur = base;
    while (exponent) {
        if (exponent & 1LL) ans = mul(ans, cur);
        cur = mul(cur, cur); exponent >>= 1LL;
    }
    return ans;
}

int Co[255][255];

int C(int x, int y)
{
    return Co[x][y];
}

int invk_pwrs[305];

int main()
{
    factorial[0] = 1;
    for (int i = 1; i <= 250; i++) factorial[i] = mul(factorial[i-1], i);
    for (int i = 0; i <= 250; i++) {
        for (int j = 0; j <= i; j++) {
            Co[i][j] = mul(factorial[i], fpow(mul(factorial[j], factorial[i-j]), MOD-2));
        }
    }
    int n, K;
    scanf("%d%d", &n, &K);
    if (K == 1) {
        printf("%d", 1); return 0;
    }
    K--;
    int kn2 = fpow(K, n * n);
    int invk = fpow(K, MOD - 2);
    invk_pwrs[0] = 1;
    for (int i = 1; i <= 300; i++) invk_pwrs[i] = mul(invk_pwrs[i-1], invk);
    f[0][n] = kn2;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= n-j; k++) {
                s[i][j] += mul(f[i-1][j], mul(C(n-j, k), invk_pwrs[k]));
                if (s[i][j] >= MOD) s[i][j] -= MOD;
            }
        }
        for (int j = 0; j <= n; j++) {
            for (int k = j; k <= n; k++) {
                f[i][j] += mul(C(k, k-j), mul(invk_pwrs[k-j], s[i][k]));
                if (f[i][j] >= MOD) f[i][j] -= MOD;
            }
            f[i][j] -= f[i-1][j];
            if (f[i][j] < 0) f[i][j] += MOD;
        }
    }
    /*for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) printf("%d ", s[i][j]);
        printf("\n");
    }*/
    printf("%d", f[n][0]);
    return 0;
}