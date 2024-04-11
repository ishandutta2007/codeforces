#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 9;

int expmod(int x, int y) {
    int r = 1;
    for(; y; y >>= 1, x=1ll*x*x%mod) if(y&1) r = 1ll*r*x%mod;
    return r;
}

char s[100010];

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k >> s;
    n ++;
    int g = n/k;
    int ans = 0;
    for(int i = 0; i < k; i ++) {
        if(s[i] == '+') ans = (ans + 1ll * expmod(b, i) * expmod(a, n-1-i)) % mod;
        else ans = (ans - 1ll * expmod(b, i) * expmod(a, n-1-i)) % mod;
    }
    a = 1ll * b * expmod(a, mod-2) % mod;
    a = expmod(a, k);
    if(a == 1) ans = 1ll * ans * g % mod;
    else ans = 1ll * ans * (1-expmod(a, g)) % mod * expmod(1-a, mod-2) % mod;
    if(ans < 0) ans += mod;
    cout << ans << endl;
}