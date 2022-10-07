#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100009],b[1009];
ll dp[1009][1009];
main(){
    ll n;
    cin >> n;
    for(ll i = 0; i < n; i++){
       cin >> a[i];
       a[i] *= 1000;
    }
    for(ll i = 0; i < n; i++){
        cin >> b[i];
    }
    ll lo = 0, hi = 1e15;
    while(lo < hi){
        vector<pair<ll,ll> > v;
        ll mid = (lo + hi)/2;
        for(ll i = 0; i < n; i++){
            v.push_back ({ a[i],-a[i] +mid * b[i] });
        }
        sort(v.rbegin(),v.rend());

        for(ll i = 0; i < n ; i++){
           ll j = i-1;
           for( j = i -1 ; j >= 0; j --){
              if(v[j].first != v[i].first) break;
           }
           ll l = i - j;
            for(ll k = 0; k <= n; k++)
                dp[i][k] = -1e18;
            for(ll k = 0; k <= n; k ++){
                for(ll t= 0 ; t <= l; t++){
                    ll s1 = 0 , s2  =0;
                    for(ll z= j +1; z <= j + t; z++)
                        s1 += v[z].second;
                    if(k + -(l - t) < 0) continue;
                    if(j == -1 && k !=0) continue;
                    if(j == -1) dp[i][t-(l-t)] = s1; else
                    dp[i][k+t-(l-t)] = max(dp[i][k+t-(l-t)], dp[j][k] + s1);
                }
            }

        }
        ll fl = 0;
        for(ll k = 0; k <= n; k++)
            if(dp[n-1][k] >= 0) fl = 1;
        if(fl) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;

}