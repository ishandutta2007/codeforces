#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 998244353;
ll dp[2001][2001];
ll dp2[2001][2001];
int n;
string s;
ll DP(int i,int j){
    if (j<0)return 0;
    if (i<0)return j==0;
    if (dp[i][j]!=-1)return dp[i][j];
    if (s[i]=='(')return dp[i][j]=DP(i-1,j-1);
    if (s[i]==')')return dp[i][j]=DP(i-1,j);
    if (s[i]=='?')return dp[i][j]=(DP(i-1,j)+DP(i-1,j-1))%mod;
}
ll DP2(int i,int j) {
    if (j<0)return 0;
    if (i>=n)return j==0;
    if (dp2[i][j]!=-1)return dp2[i][j];
    if (s[i]==')')return dp2[i][j]=DP2(i+1,j-1);
    if (s[i]=='(')return dp2[i][j]=DP2(i+1,j);
    if (s[i]=='?')return dp2[i][j]=(DP2(i+1,j)+DP2(i+1,j-1))%mod;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    memset(dp,-1,sizeof(dp));
    memset(dp2,-1,sizeof(dp2));
    n = s.size();
    for (int i=0;i<n;i++) {
        for (int j=0;j<=n;j++){
            DP2(i,j);
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=n-1;j>=0;j--){
            dp2[i][j]=(dp2[i][j]+dp2[i][j+1])%mod;
        }
    }
    ll ret=0;
    for (int i=0;i+1<n;i++) {
        if (s[i]==')')continue;
        for (int j=1;j<=n;j++) {
            ll L = DP(i-1,j-1);
            ll R = dp2[i+1][j];
            ret+=(L*R)%mod;
            ret%=mod;
        }
    }
    cout<<ret<<endl;
}