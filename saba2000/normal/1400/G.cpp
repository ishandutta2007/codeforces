#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 998244353 ;
const ll N = 3e5+10;
ll inv[N],fi[N],fc[N],l[N],ea[N],r[N],eb[N],ps[N][50],f[N];
ll C(ll m,ll n){
    if(m < n || n<0)return 0;
    return fc[m] * fi[n]%mod *fi[m-n]%mod;
}
main(){
    ios_base::sync_with_stdio(false);
    ll n, m;
    cin>>n>>m;
    fi[0] = 1; fc[0] = 1;
    inv[1] = 1; inv[0] = 1;
    fi[1]= 1; fc[1] = 1;
    for(ll i= 2; i <= n; i++){
        inv[i] = inv[mod % i]*(mod-mod/i)%mod;
        fc[i] = fc[i-1] *i%mod;
        fi[i] = fi[i-1] * inv[i]%mod;
    }
    for(ll i = 1; i <= n; i++){
        cin >>l[i]>>r[i];
        f[l[i]]++;
        f[r[i]+1]--;
    }
    for(ll i = 1; i <= n; i++)
        f[i]+=f[i-1];
    for(ll i = 1; i <= n; i++){
        for(ll j  =0; j <=2*m; j++){
            ps[i][j] = (ps[i-1][j] + C(f[i]-j,i-j))%mod;
        }
    }
    for(ll i = 0; i< m; i++){
        cin >> ea[i] >> eb[i];
    }
    ll ans =0;
    for(ll b = 0; b<(1<<m); b++){
        set<ll> s;
        for(ll i = 0; i < m; i++)
            if((1<<i) & b) s.insert(ea[i]), s.insert(eb[i]);
        ll L = 1, R = n;
        for(auto it = s.begin(); it!=s.end(); it++){
            ll u = *it;
            L = max(L, l[u]);
            R = min(R, r[u]);
        }
        if(L > R) continue;
        ll sz = s.size();
        ll cnt = (ps[R][sz] - ps[L-1][sz]+mod)%mod;
        if(__builtin_popcount(b) %2 == 0) ans =(ans + cnt) %mod;
        else ans =(ans -cnt+mod)%mod;
    }

    cout<<ans<<endl;

}