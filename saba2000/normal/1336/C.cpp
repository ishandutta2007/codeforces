#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[3009][3009];
ll dp1[3009][3009];
ll W[3009][3009];
ll pw[3009];
int ok[3009];
ll mod = 998244353;
main(){
    string s,t;
    cin>>s>>t;
    int n = s.size();
    int m = t.size();
    for(int l = 0; l < m; l++){
        for(int i = 0; i + l < m; i++){
            int j = i + l;
            if(!l){
                if(s[0] == t[i]) W[i][j] = 2;
                else W[i][j] = 0;
            }
            if(s[l] == t[i]) W[i][j] = (W[i][j] + W[i+1][j]) % mod;
            if(s[l] == t[j]) W[i][j] = (W[i][j] + W[i][j-1]) % mod;
        }
    }
    for(int i = 0; i < m; i++)
        if(t[m-1] == s[i]) {if(!i) dp[i+1][i+1] = 1; else dp[i+1][i+1] = W[m-i-1][m-2];}
    ll ans = 0;
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= m; j++)
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
        dp[i][0] = 2 * dp[i-1][0] % mod;

        for(int j = 1; j <= m; j++){
            if(s[i-1] == t[m - j])
                dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
        }
        ans = (ans + dp[i][m]) % mod;
    }
    cout<<ans<<endl;
}