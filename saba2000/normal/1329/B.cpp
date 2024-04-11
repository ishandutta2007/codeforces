#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[32][32];
ll x[32];
void solve(){
    ll d, m;
    cin >> d >> m;
    ll ans = 1;
    for(ll i = 0; i <= 30; i++){
        if((1ll<<i) > d) x[i] = 0;
        else if(((1ll<<(i+1))-1) <= d) x[i] = (1ll<<i);
        else x[i] = d - (1ll<<i) + 1;
        ans = ans * (1 + x[i]) % m;
    }
    cout << (ans - 1 + m)%m << endl;
}

main(){
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}