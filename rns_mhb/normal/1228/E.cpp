#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int x, int y) {
    int r = 1;
    for(; y; y >>= 1, x = 1ll * x * x % mod) if(y & 1) r = 1ll * r * x % mod;
    return r;
}

#define N 255

int dp[N], c[N][N];

int main() {
    int n, k;
    cin >> n >> k;
    if(k == 1) {
        puts("1");
        return 0;
    }
    for(int i = 0; i < N; i ++) c[0][i] = 0, c[i][0] = 1;
    for(int i = 1; i < N; i ++) for(int j = 1; j < N; j ++)
        c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    dp[1] = 1;
    for(int i = 2; i <= n; i ++) {
        dp[i] = expmod(expmod(k, i) - expmod(k-1, i), n);
        for(int j = 1; j < i; j ++)
            dp[i] = (dp[i] - 1ll * c[i][j] * dp[j] % mod * expmod(k-1, (i-j)*n)) % mod;
        if(dp[i] < 0) dp[i] += mod;
    }
    cout << dp[n] << endl;
}