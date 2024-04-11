#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 998244353;
ll f[2000009],fi[2000009],inv[2000009];
ll dp[2000009], d[2000009];
main(){
    int n;
    cin >> n;
    ll S = 1;
    dp[1] = 1;
    for(int  i = 1; i <= n; i++)
        for(int j = i; j <= n; j+=i)
            d[j]++;
    for(int i = 2; i <= n; i++){
        dp[i] = (S + d[i])%mod;
        S = (S + dp[i]) % mod;
    }
    cout<<dp[n]<<endl;
}