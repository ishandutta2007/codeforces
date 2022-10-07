#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200009],w[200009];
ll ans;
main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        ll n,  k;
        cin >> n >> k;
        for(ll i = 1; i <= n; i++){
            cin >> a[i];
        }
        ll u = 0;
        for(ll i =1 ; i <= k; i++){
            cin >> w[i];
            if(w[i] == 1) u++;
        }
        sort(a+1,a+n+1);
        sort(w+1,w+k+1);
        ans = 0;
        for(ll i = n; i >= n - k + 1; i--){
            ans += a[i];
            if(i >= n - u +1) ans += a[i];
        }
        ll j = n - k;
        for(ll i = 1; i <= k; i++){
            if(w[i] == 1) continue;
            ans += a[j - w[i] + 2];
            j -= w[i] - 1;
        }
        cout<<ans<<endl;
    }
}