#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 998244353;
int c[500009];
ll dp[500009];
ll F(ll l, ll d){
    if(!l) return d + 1;
    return (dp[l] * (d + 1) + dp[l-1] * (9 - d)) % mod;
}
set<pair<ll,ll> > s;
ll exp( ll a, ll b){
    if(!b) return 1;
    if(b&1) return a * exp(a * a % mod, (b-1)/2) % mod;
    return exp(a*a% mod, b/2);
}
ll inv(ll u){
    return exp(u, mod-2);
}
main(){
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    dp[0] = 1;
    dp[1] = 2;
    for(ll i = 1; i <= n; i++){
        dp[i] = (dp[i-1] * 2 + dp[i-2] * 8) % mod;
    }
    string num;
    cin >> num;
    ll ans = 1, o = 0;
    for(ll i = 1; i <= n; i++){
        c[i] = num[i-1] - '0';
        if(c[i] == 1) o++;
        else {
            ans = ans * F(o, c[i]) % mod;
            if(o) s.insert({i - o, i - 1});
            o = 0;
        }
    }
    ans = ans * dp[o] % mod;
    if(o) s.insert({n - o + 1, n});
    int mx = m;
    while(m--){
        if(m < mx -1 ) cout << ans << endl;
        ll x, d;
        cin >> x >> d;
        if(c[x] == d) continue;
        ll w = c[x]; c[x] = d;
        if(w != 1){
            auto it = s.lower_bound({x,-1});
            ll N = 0;
            if(it != s.begin()){
                it--;
                if(it->second == x-1){
                    N = it->second - it->first + 1;
                    s.erase(it);
                }
            }
            ans = ans * inv(F(N, w)) % mod;
            if(d != 1) {
                ans = ans * F(N, d) % mod;
                if(N) s.insert({x-N, x-1});
                continue;
            }
            it = s.lower_bound({x,-1});
            ll P,r;
            if(it == s.end() || it->first > x + 1){
                P = 0, r = x;
            } else
            P = it->second - it->first + 1, r = it->second,s.erase(it);
            s.insert({x-N, x+P});
            if(r == n){
                ans = ans * inv(dp[P]) % mod;
                ans = ans * dp[P + N + 1] % mod;
            }
            else{
                ll D = c[r+1];
                ans = ans * inv(F(P, D)) % mod;
                ans = ans * F(P+N+1, D) % mod;
            }
        }
        else{
            auto it = s.lower_bound({x+1, -1});
            it--;
            ll l = it->first, r = it->second, N = r - l + 1;
            s.erase(it);
            if(x > l) s.insert({l, x-1});
            if(x < r) s.insert({x+1, r});
            if(r == n) ans = ans * inv(dp[N]) % mod * dp[r - x] % mod;
            else ans = ans * inv(F(N, c[r+1]))% mod * F(r-x, c[r+1]) % mod;
            ans = ans * F(x-l, d) % mod;
        }
    }
    cout<<ans<<endl;
}