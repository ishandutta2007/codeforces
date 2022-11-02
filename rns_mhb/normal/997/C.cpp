#include<bits/stdc++.h>
using namespace std;

#define L 20

namespace MOD{
    const int FN = 1 << L;
    const int mod = 998244353;
    int expmod(int x, int y, int z) {
        int ret = 1;
        for(; y; y>>=1, x=1ll*x*x%z) if(y&1) ret = 1ll * ret * x % z;
        return ret;
    }
    int fac[FN], rfac[FN], inv[FN];
    void init() {
        fac[0] = inv[1] = rfac[0] = 1;
        for(int i=1;i<FN;i++)fac[i]=1ll*fac[i-1]*i%mod;
        for(int i=2;i<FN;i++)inv[i]=mod-1ll*inv[mod%i]*(mod/i)%mod;
        for(int i=1;i<FN;i++)rfac[i]=1ll*rfac[i-1]*inv[i]%mod;
    }
}
using namespace MOD;

int C(int n, int m) {
    return 1ll * fac[n] * rfac[m] % mod * rfac[n-m] % mod;
}

int main() {
    MOD::init();
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int val = 1ll * C(n, i) * expmod(3, i, mod) % mod * expmod(3, 1ll*(n-i)*n%(mod-1), mod) % mod;
        if(i & 1) {
            ans += val;
            if(ans >= mod) ans -= mod;
        }
        else {
            ans -= val;
            if(ans < 0) ans += mod;
        }
    }
    for(int i = 1; i <= n; i ++) {
        int v1 = 1ll * (expmod(3, i, mod) - 3) * expmod(3, 1ll*(n-i)*n%(mod-1), mod) % mod;
        int v2 = 3ll * expmod((expmod(3, n-i, mod)-1), n, mod) % mod;
        int val = 1ll * C(n, i) * (v1 + v2) % mod;
        if(val < 0) val += mod;
        if(i & 1) {
            ans += val;
            if(ans >= mod) ans -= mod;
        }
        else {
            ans -= val;
            if(ans < 0) ans += mod;
        }
    }
    cout << ans << endl;
}