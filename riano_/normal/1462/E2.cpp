#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Pr pair<ll,ll>
#define Tp tuple<ll,ll,ll>
using Graph = vector<vector<int>>;
#define double long double

const ll mod = 1000000007;


//Combination2
//10^6
//mod
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
vector<ll> fact;
vector<ll> invf;
ll comb(ll n,ll k){
    if(n<0||k<0||k>n) return 0LL;
    else{
        ll a = fact[n]*invf[k]%mod;
        a = a*invf[n-k]%mod;
        return a;
    }
}
    



int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    ll T; cin >> T;
    //main
    //N:max
    ll N1 = 200002;
    fact.assign(N1+1,1LL);
    invf.assign(N1+1,1LL);
    rep(i,N1) fact[i+1] = fact[i]*(i+1)%mod;
    rep(i,N1+1) invf[i] = modinv(fact[i],mod);
    rep(ii,T){
        ll N,M,K; cin >> N >> M >> K;
        ll cnt[N+1];
        rep(i,N+1) cnt[i] = 0;
        rep(i,N){
            ll a; cin >> a;
            cnt[a]++;
        }
        ll sum[N+2]; sum[0] = 0;
        rep(i,N+1){
            sum[i+1] = sum[i] + cnt[i];
        }
        ll ans = 0;
        rep(i,N+1-K){
            ll cc = sum[K+i+1]-sum[i];
            ans += comb(cc,M); ans %= mod;
        }
        rep(i,N-K){
            ll cc = sum[K+i+1]-sum[i+1];
            ans += mod-comb(cc,M); ans %= mod;
        }
        cout << ans << endl;
    }
    //cout << ans << endl;
}