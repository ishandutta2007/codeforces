#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m;
ll a[100009], b[100009];
void solve(){
    cin >> n >> m;
    ll ans = 0;
    ll zr = 0;
    vector<pair<ll,ll> > v, w;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        ll p = 1;
        while(a[i] % m == 0){
            a[i] /= m;
            p *= m;
        }
        if(v.size() == 0 || v.back().first != a[i]){
            v.push_back({a[i], p});
        }
        else v.back().second += p;
    }
    int k;
    cin >> k;
    for(ll i = 1; i <= k; i++){
        cin >> b[i];
        ll p = 1;
        while(b[i] % m == 0){
            b[i] /= m;
            p *= m;
        }
        if(w.size() == 0 || w.back().first != b[i]){
            w.push_back({b[i], p});
        }
        else w.back().second += p;
    }
    if(v == w) cout <<"Yes"<<endl;
    else cout<<"No"<<endl;

}
main(){
    ll t; // = 1;
    cin >> t;
    while(t--){
        solve();
    }

}