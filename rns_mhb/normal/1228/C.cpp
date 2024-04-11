#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int expmod(int x, ll y) {
    int r = 1;
    for(; y; y>>=1, x=1ll*x*x%mod) if(y&1) r = 1ll*r*x%mod;
    return r;
}

int main() {
    int x;
    ll n;
    cin >> x >> n;
    int d = sqrt(x + 1), ans = 1;
    for(int i = 2; i <= d; i ++) if(x % i == 0) {
        while(x % i == 0) x /= i;
        ll m = n;
        while(1) {
            m /= i;
            if(m == 0) break;
            ans = 1ll * ans * expmod(i, m) % mod;
        }
    }
    if(x > 1) {
        ll m = n;
        while(1) {
            m /= x;
            if(m == 0) break;
            ans = 1ll * ans * expmod(x, m) % mod;
        }
    }
    cout << ans << endl;
}