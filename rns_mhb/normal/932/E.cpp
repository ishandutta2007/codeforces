#include <bits/stdc++.h>
using namespace std;

#define N 5005

const int mod = 1e9 + 7;

int n, k;
int dp[N][N];

int powmod(int a, int b) {
    int rtn = 1;
    for (; b; b >>= 1) {
        if (b & 1) rtn = 1ll * rtn * a % mod;
        a = 1ll * a * a % mod;
    }
    return rtn;
}

void calc_dp() {
    for (int i = 0; i <= k; i ++) {
        for (int j = 0; j <= k; j ++) {
            if (!i) {
                if (!j) dp[i][j] = powmod(2, n);
                else dp[i][j] = 1ll * dp[i][j-1] * powmod(2, mod - 2) % mod;
            }
            else {
                dp[i][j] = (1ll * j * dp[i-1][j] % mod + 1ll * (n - j) * dp[i-1][j+1] % mod) % mod;
            }
        }
    }
}

int main() {
    scanf("%d %d", &n, &k);
    calc_dp();
    printf("%d\n", dp[k][0]);
    return 0;
}