#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long dp[59][59];
int f[59][59];
long long n, k;
long long a[58];
main(){
    cin>>n>>k;
    for(ll i= 1; i <= n; i++){
        cin>>a[i];
    }
    ll ans = 0;
    for(ll i = 58; i >= 0; i--){
        ans |= (1LL <<i);
        for(ll i = 1; i <= n; i++){
            ll K = 0;
            for(ll j = i; j <= n; j++){
                K+= a[j];
                if((K & ans) == ans) f[i][j] = 1;
                else f[i][j] = 0;
              //  if(ans == 16) cout << i<<" "<<j<<" "<<f[i][j]<<endl;
            }
        }
            for(ll i =1; i<=n; i++)
                for(ll j = 1; j <= n; j++)
                    dp[i][j] = 0;
            dp[0][0] = 1;
            for(ll i = 1; i <= n; i++){
                for(ll j =  1; j <= k; j++){
                    for(ll p = i; p >= 1; p--)
                        if(f[p][i] && dp[p-1][j-1]) dp[i][j] =1;
              //     if(ans== 16)cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                }
            }

            if(!dp[n][k]) ans ^= (1LL << i);
    }
    cout<<ans<<endl;

}