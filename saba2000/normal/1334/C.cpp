#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[300009],b[300009];
void solve(){
    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
       scanf("%lld %lld", &a[i] , &b[i]);
    }
    ll X = 1e18;
    ll ans  =0;
    for(ll i = 1; i <= n; i++){
        if(b[i] >= a[i%n+1]) b[i] = a[i%n+1];
        ans += a[i] - b[i];
        X = min(X, b[i]);
    }
    printf("%lld\n", ans+X);
}

main(){
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}