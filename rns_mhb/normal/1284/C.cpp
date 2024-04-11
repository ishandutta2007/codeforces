#include<bits/stdc++.h>
using namespace std;

int mod;

int expmod(int x, int y) {
    int r = 1;
    while(y) {
        if(y & 1) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return r;
}

#define N 300010

int fac[N];

int main() {
    int n;
    cin >> n >> mod;
    fac[0] = 1;
    for(int i = 1; i < N; i ++) fac[i] = 1ll * fac[i-1] * i % mod;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        ans = (ans + 1ll * (n-i+1) * (n-i+1) % mod * fac[i] % mod * fac[n-i]) % mod;
    }
    cout << ans << endl;
}