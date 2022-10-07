#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000009], b[2000009], sa[2000009],sb[2000009];
bool solve(){
    ll n;
    cin >> n;
    for(ll i =1 ; i <= n; i++){
        cin >> a[i];
        sa[i] = sa[i-1] + a[i];
    }
    for(ll i = 1; i <= n; i++){
        cin >> b[i];
        sb[i] = sb[i-1] + b[i];

    }
    for(ll i = 1 ;i <= n; i++){
        sa[i+n] = sa[i+n-1] + a[i];
        sb[i+n] = sb[i+n-1] + b[i];
    }
    if(sa[n] > sb[n]) return 0;
    ll m = -sa[1];
    for(ll i = 1; i <= 2*n; i++){
        ll x = sb[i] - sa[i];
        if(x < m) return 0;
        m = max(m, sb[i] - sa[i+1]);
    }
    return 1;

}
main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
       cout<< (solve() ? "YES" : "NO" )<<endl;
    }
}