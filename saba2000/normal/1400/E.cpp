#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(vector<ll> v){
    if(!v.size())return 0;
    vector<ll> a;
    ll ans = 0,m=v[0],o = 0;
    for(ll i = 0; i<v.size(); i++)
        m=min(m,v[i]);
    for(ll i = 0; i<v.size(); i++){
        if(v[i] ==m) {ans+=solve(a);a.clear();}
        else a.push_back(v[i]-m);
    }
    return min((ll)v.size(), m+ans+solve(a));
}
main(){
    ios_base::sync_with_stdio(false);
    ll n;
    cin>>n;
    vector<ll> v;
    for(ll i = 1; i <= n; i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    cout<<solve(v)<<endl;
 
}