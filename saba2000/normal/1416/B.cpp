#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[10009];
main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin>>n;
        ll S = 0;
        for(ll i= 1; i <= n; i++){
            cin >> a[i];
            S += a[i];
        }
        if(S % n){
            cout << -1 << endl;
            continue;
        }
        ll x = S / n;
        S = 0;
        vector<vector<ll> > ans;
        for(ll i = 2; i <= n; i++){
            ll x = (i - a[i] % i) % i;
            ans.push_back({1, i, x});
            ans.push_back({i, 1, (a[i] + x)/i});
        }
        for(ll i = 2; i <= n; i++){
            ans.push_back({1,i,x});
        }
        cout<<ans.size()<<endl;
        for(auto u : ans)
            cout<<u[0]<<" "<<u[1]<<" "<<u[2]<<endl;



    }

}