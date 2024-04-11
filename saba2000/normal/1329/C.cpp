#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[4000009];
ll F[4000009];
ll h, g;
ll ha(ll i){
    ll l = 2 * i;
    ll r = 2 * i +1;
    if(!a[l] && !a[r]) return i;
    if(a[l] > a[r]) return ha(l);
    else return ha(r);
}
void f(ll i){
    ll l = 2 * i;
    ll r = 2 * i +1;
    if(!a[l] && !a[r]) {a[i] = 0; return;}
    if(a[l] > a[r]) {a[i] = a[l]; F[a[i]] = i; f(l);}
    else {a[i] = a[r]; F[a[i]] = i; f(r);}
}
void solve(){
    cin >> h >> g;
    ll n = (1 << h) - 1;
    vector<int> w; 
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        w.push_back(a[i]);
        F[a[i]] = i;
    }
    sort(w.begin(), w.end());
    ll x = w.size()-1;
    ll m = (1 << h) - (1 << g);
    vector<ll>v ;
    while(m--){
        while(!F[w[x]] || ha(F[w[x]]) < (1<<g)) x--;
        v.push_back(F[w[x]]);
        f(F[w[x]]);
        F[w[x]] = 0;
    }
    ll ans = 0;
    for(ll i = 1; i < (1<<g); i++)
        ans += a[i], F[a[i]] = 0;
    cout<<ans<<endl;
    for(ll x : v)
        cout <<x<<" ";
    cout<<endl;
    for(ll i = 1; i <= n; i++)
    a[i] = 0;
}

main(){
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }

}