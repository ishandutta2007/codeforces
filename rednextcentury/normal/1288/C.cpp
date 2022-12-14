#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m;
ll mod = 1000000007;
ll dp[11][1001][1001];
ll sol(int i,int a,int b) {
    if (a<=0 || a>n || b<=0 || b>n)return 0;
    if (i==m)return 1;
    if (dp[i][a][b]!=-1)return dp[i][a][b];
    ll &ret = dp[i][a][b];
    ret=sol(i,a-1,b)+sol(i,a,b+1) - sol(i, a-1,b+1)+mod;
    if (a>=b)ret+=sol(i+1,a,b);
    ret%=mod;
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    cout<<sol(0,n,1)<<endl;
}