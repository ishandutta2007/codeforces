#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000009];
ll S[1000009];
main(){
    ll n;
    cin >> n;
    stack<pair<ll,ll> > S;
    for(ll i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ll x = a[i], r = 1;
        while(S.size() && r * S.top().first > x * S.top().second){
            x += S.top().first;
            r += S.top().second;
            S.pop();
        }
        S.push({x,r});
    }
    vector<pair<ll,ll> > ans;
    while(S.size())
        ans.push_back(S.top()),
        S.pop();
    reverse(ans.begin(),ans.end());
    for(auto x : ans){
        for(ll y = 0; y < x.second; y++)
            printf("%.10f\n", 1.0*x.first / x.second);
    }



}