#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000009];
main(){
    ll n,k1,k2;
    cin >> n>> k1 >> k2;
    ll k = k1+k2;
    for (ll i = 0 ; i < n; i++){
        cin >> a[i];
    }
    for (ll i = 0; i < n; i++){
        ll b;
        cin >> b;
        a[i] -=b;
        a[i] = max(a[i], -a[i]);
    }
    multiset<ll > s;
    ll ans = 0;
    for (ll i = 0; i < n; i++)
        s.insert(a[i]);
    while(k--){
        auto X = s.end();
        X--;
        ll K = *X;
        s.erase(X);
        s.insert(abs(K-1));
    }
    while(s.size()){
        ll x = *s.begin();
        ans += x*x;
        s.erase(s.begin());
    }
    cout << ans << endl;

}