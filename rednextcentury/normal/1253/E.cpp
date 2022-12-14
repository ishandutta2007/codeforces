#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define L (x<<1)
#define R (L+1)
#define mid (l+r)/2
ll dp[1000000];
int x[1000],s[1000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>x[i]>>s[i];
    for (int i=1;i<=m;i++) dp[i]=i;
    for (int i=1;i<=m;i++) {
        for (int j=0;j<n;j++) {
            if (x[j]>i)continue;
            int cost = max(0,i-x[j]-s[j]);
            dp[i] = min(dp[i],dp[max(x[j]-s[j]-cost-1,0)]+cost);
        }
        for (int j=0;j<n;j++) {
            if (x[j]<=i)continue;
            int cost = max(0,x[j]-s[j]-i);
            dp[i] = min(dp[i],dp[max(x[j]-s[j]-cost-1,0)]+cost);
        }
        //for (int j=m-1;j>=1;j--)dp[j]=min(dp[j],dp[j+1]);
    }
    cout<<dp[m]<<endl;
}