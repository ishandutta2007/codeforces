#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9 + 7;
ll a[1000009], P[1000009];
ll exp(ll a, ll b){
    if(!b) return 1;
    if(b & 1) return a * exp(a * a % mod, b/2) % mod;
    return exp(a*a%mod, b/2) % mod;
}
void solve(){
    ll n, p;
    cin >> n >> p;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll j = 0;
    P[0] = 1;
    if(p == 1){
        cout<< n % 2 <<endl;
        return;
    }
    while(P[j] * p < n) j++, P[j] = P[j-1] * p;

    sort(a+1,a+n+1);
    ll m = 0, K = a[n], ans = 0;
    for(ll i = n; i >= 1; i--){
        ll x = a[i+1] - a[i];
        if(m){
            if(x <= j) {m = m * P[x];
                if(m > n) m = n;
            }
            else{
                m = n;
            }
        }
        if(m) ans = (ans - exp(p, a[i]) +mod)% mod, m--;
        else m = 1, ans = (ans + exp(p, a[i]))% mod;

    }
    cout<<ans<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }


}