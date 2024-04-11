#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> v[200009];
int p[200009];
int a[200009];
main(){
    for(ll i = 2; i <= 2e5; i++){
        if(p[i]) continue;
        for(ll j = i; j <= 2e5; j+= i)
            p[j] = i;
    }

    ll n;
    cin >> n;
    for(ll i = 1; i <= n; i++){
        ll x;
        cin>>x;
        while(x > 1){
            ll k = 0;
            ll y = p[x];
            while(x % y == 0){
                x /= y;
                k++;
            }
            v[y].push_back(k);
        }
    }
    ll ans= 1;
    for(ll i = 2; i <= 2e5; i++){
        sort(v[i].begin(), v[i].end());
        ll x = 0;
        if(v[i].size() == n){
            x = v[i][1];
        }
        else if(v[i].size() == n-1)
            x = v[i][0];
        for(ll j = 0; j < x; j++)
            ans *= i;

    }
    cout<<ans<<endl;

}