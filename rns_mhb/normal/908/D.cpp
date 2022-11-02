#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int x, int y) {
    int r = 1;
    while(y) {
        if(y & 1) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return r;
}

#define N 1010

int dp[N][N];

int main() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int r = expmod(a+b, mod-2);
    a = 1ll * a * r % mod;
    b = 1ll * b * r % mod;
    dp[1][0] = 1;
    for(int i = 1; i <= n; i ++) for(int j = 0; j <= n; j ++) {
        if(i < n) dp[i+1][j] = (dp[i+1][j] + 1ll * a * dp[i][j]) % mod;
        if(i+j < n) dp[i][i+j] = (dp[i][i+j] + 1ll * b * dp[i][j]) % mod;
    }
    int ans = 0;
    for(int i = 1; i < n; i ++) for(int j = 0; j < n; j ++) if(i+j >= n)
        ans = (ans + 1ll * dp[i][j] * (i+j)) % mod;
    ans = 1ll * ans * b % mod;
    a = 1ll * a * expmod(b, mod-2) % mod;
    for(int j = 0; j < n; j ++) ans = (ans + 1ll * dp[n][j] * (j+n+a)) % mod;
    cout << ans << endl;
}