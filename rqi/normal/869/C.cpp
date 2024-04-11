#include <bits/stdc++.h>

typedef long long ll;

using namespace std;
const long long MOD = 998244353;
ll ifac[5003];
ll fac[5003];
ll po(ll b, ll p) {
    return !p?1:po(b*b%MOD,p/2)*(p&1?b:1) % MOD;
}

ll inv (ll b) {
    return po(b,MOD-2);
}


ll com (ll a, ll b) {
    ll c = fac[a];
    c*=ifac[b];
    c%=MOD;
    c*=ifac[a-b];
    c%=MOD;
    return c;
}


int main() {
    long long ans = 1;
    long long a, b, c;
    cin >> a >> b >> c;
    long long ans1 = 1;
    long long ans2 = 0;
    
    fac[0] = 1;
    ifac[0] = 1;
    for(int i = 1; i < 5003; i++){
        fac[i] = (fac[i-1] * i) % MOD;
        ifac[i] = (ifac[i-1] * inv(i)) % MOD;
    }
    ll x = min(a,b);
    ll y = max(a,b);
    for(ll i = 0; i < x+1; i++){
        ans*= com(x,i);
        ans %= MOD;
        ans*= com(y,i);
        ans %= MOD;
        ans*= fac[i];
        ans%= MOD;
        ans2 = (ans2 + ans) % MOD;
        
        ans = 1;
    }
    ans1*=ans2;
    ans1 %= MOD;
    ans2 = 0;
    x = min(a,c);
    y = max(a,c);
    for(ll i = 0; i < x+1; i++){
        ans*= com(x,i);
        ans %= MOD;
        ans*= com(y,i);
        ans %= MOD;
        ans*= fac[i];
        ans%= MOD;
        ans2 += ans;
        ans2%= MOD;
        ans = 1;
    }
    ans1*=ans2;
    ans1%= MOD;
    ans2 = 0;
    x = min(b,c);
    y = max(b,c);
    for(ll i = 0; i < x+1; i++){
        ans *= com(x,i);
        ans %= MOD;
        ans *= com(y,i);
        ans %= MOD;
        ans *= fac[i];
        ans %= MOD;
        ans2 += ans;
        ans2 %= MOD;
        ans = 1;
    }
    ans1 *= ans2;
    ans1 %= MOD;
    cout << ans1;
}