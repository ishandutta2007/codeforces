#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A[100009], B[100009];
vector<ll> v[100009];
ll ans[100009];
void dfs(ll x, ll p){
    vector<ll> d;
    for(ll y : v[x]){
        if(y == p) continue;
        dfs(y, x);
        B[x] += A[y];
        A[x] += A[y];
        d.push_back(B[y] - A[y] + 2);
    }
    if(d.size() == 0){
        A[x] = 1e9;
        B[x] = 0;
        return;
    }
    sort(d.begin(), d.end());
    ll S = d[0];
    for(ll i = 1; i < d.size(); i++){
        if(d[i] > 0) break;
        S += d[i];
    }
    A[x] += S;
    if(S < 0) B[x] += S;
}
void recov(ll x, ll p, ll t){
     vector<pair<ll,ll> > d;
    for(ll y : v[x]){
        if(y == p) continue;
        d.push_back({B[y] - A[y] + 2, y});
    }
    if(d.size() == 0){
        return;
    }
    sort(d.begin(), d.end());
    ll S = d[0].first, i;
    for(i = 1; i < d.size(); i++){
        if(d[i].first > 0) break;
        S += d[i].first;
    }
    if(t == 0){
        if(i == 2){
            ans[d[0].second] = x;
            ans[x] = d[1].second;
            ans[d[1].second] = d[0].second;
        }
        else{
            ans[d[0].second] = x;
            ans[x] = d[0].second;

            for(ll j = 1; j < i; j++){
                if(j == 1) ans[d[j].second] = d[i-1].second;
                else ans[d[j].second] = d[j-1].second;
            }
        }
        for(ll j = 0; j < d.size(); j++){
            if(j < i) recov(d[j].second, x, 1);
            else recov(d[j].second, x, 0);
        }
    }
    else{
        if(S > 0) i = 0;
        if(i == 1){
            ll u = d[0].second;
            ans[u] = ans[x];
            ans[x] = u;
        }
        else if(i){
            for(ll j = 0; j < i; j++){
                if(j == 0) ans[d[j].second] = d[i-1].second;
                else ans[d[j].second] =  d[j-1].second;
            }
        }
        for(ll j = 0; j < d.size(); j++){
            if(j < i) recov(d[j].second, x, 1);
            else recov(d[j].second, x, 0);
        }
    }
}
main(){
    ll n;
    cin >> n;
    for(ll i = 1; i < n; i++){
        ll a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(1, 0);
    cout << A[1]<<endl;
    recov(1, 0, 0);
    for(ll i = 1; i <= n; i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}