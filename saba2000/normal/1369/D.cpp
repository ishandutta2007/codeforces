#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2000009];
ll mod = 1e9 + 7;
main(){
    dp[1] = 0;
    dp[2] = 0;
    dp[3] = 1;
    dp[4] = 1;
    for(ll i = 5; i <= 2000000; i++){
        if(i % 3) dp[i] = dp[i-1] + 2*dp[i-2];
        else dp[i] = 1+dp[i-2]+2*dp[i-3] + 2*(dp[i-3] + 2*dp[i-4]);
        dp[i] %= mod;
    }
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >>n;
        cout<<dp[n]*4%mod<<endl;
    }
}