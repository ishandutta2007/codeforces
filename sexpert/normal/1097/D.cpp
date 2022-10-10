#include <bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n, k, dp[55][10005], inv[55];
 
long long binpow(long long a, long long b) {
    a %= mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
inline int esperanza(long long p, int r){
    dp[r][0]=1;
    for (int i=0; i<r; i++){
        dp[i][0]=0;
    }
    for (int j=1; j<=k; j++){
        for (int i=0; i<=r; i++){
            dp[i][j] = 0;
            for (int s=r; s>=i; s--){
                dp[i][j] = (dp[i][j] + dp[s][j-1]*inv[s+1]) % mod;
            }
        }
    }
    int total = 0;
    for (int i=0; i<=r; i++){
        total = (total + binpow(p, i)*dp[i][k]) % mod;
    }
    return total;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    inv[1]=1;
    for (int i=2; i<=55; i++){
        inv[i]=binpow(i, mod-2);
    }
    long long ans = 1;
    for (long long i = 2; i*i<=n; i++){
        int potencia = 0;
        while (n % i == 0){
            potencia++;
            n = n / i;
        }
        if (potencia == 0) continue;
        ans *= esperanza(i, potencia), ans %= mod;
    }    
    if (n != 1){
        ans *= esperanza(n, 1), ans %= mod;
    }
    cout << ans;
    return 0;
}