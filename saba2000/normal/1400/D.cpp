#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[3009];
ll dp0[3009],dp01[3009],dp010[3009];
vector<ll>v[3009];
void solve(){
    ll n;
    cin>>n;
    for(ll i = 1; i <= n; i++)
        v[i].clear();
    for(ll i = 1; i <= n; i++){
        cin>>a[i];
        v[a[i]].push_back(i);

    }
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        ll u = v[i].size();
        ans += u*(u-1)*(u-2)*(u-3)/24;
        for(ll j = 1; j<= n; j++){
            ll x =0,y =0,c=0;
            if(i==j)continue;
            while(x<v[i].size() || y<v[j].size()){
                c++;
                dp0[c]=dp0[c-1];
                dp01[c]=dp01[c-1];
                dp010[c]=dp010[c-1];
                if(x==v[i].size() || (y<v[j].size() && v[j][y] < v[i][x])){
                    y++;
                    dp01[c] += dp0[c-1];
                    ans+=dp010[c-1];
                }
                else{
                    x++;
                    dp0[c]++;
                    dp010[c] += dp01[c-1];
                }
            }
        }
    }
    cout<<ans<<endl;
}
main(){
    ios_base::sync_with_stdio(false);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }

}