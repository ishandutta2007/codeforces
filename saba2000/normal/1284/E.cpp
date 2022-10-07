#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll X[2509],Y[2509];
bool crs(pair<ll,ll> a, pair<ll,ll> b){
    return a.first *b.second - a.second*b.first < 0;
}
ll q(pair<ll,ll> a){
    if (a.first >= 0 || (a.first == 0 && a.second > 0)) return 1;
    else return 2;
}
bool comp(pair<ll,ll> a, pair<ll,ll> b){
    if(q(a) == q(b)) return crs(a,b);
    else return q(a) < q(b);
}
ll x[3009],y[3009];
main(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
    long long ans  =0;
    for(ll i = 1; i <= n; i++){
        ll c = 0;
        vector<pair<ll,ll> > v;
        for(ll j = 1; j <= n; j++){
            if(j != i) v.push_back({x[j] - x[i], y[j] - y[i]});
        }
        sort(v.begin(),v.end(),comp);
        ll u = 1;
        long long A = ((long long)(n-1))*(n-2)*(n-3)/6;
        for(ll j= 0; j < v.size(); j++){
            while(u != j && crs(v[j],v[u])) u = (u+1)%(n-1);

            ll t = (u - j + n-2+n-1)%(n-1);
            A -= t*(t-1)/2;
        }
        ans += A * (n - 4)/2;
    }
    cout<<ans<<endl;

}