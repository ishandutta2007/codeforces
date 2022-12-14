#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s1[1000000];
ll s2[1000000];
ll dp[1000000];
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    for (int i=1;i<n;i++)scanf("%d",&s1[i]),s1[i]+=s1[i-1];
    for (int i=1;i<n;i++)scanf("%d",&s2[i]),s2[i]+=s2[i-1];
    ll mn1 = 0,mn2 = 0;
    dp[1]=0;
    for (int i=2;i<=n;i++) {
        dp[i] = min(mn1+s1[i-1],mn2+s2[i-1]+c);
        mn1 = min(mn1,dp[i]-s1[i-1]);
        mn2 = min(mn2,dp[i]-s2[i-1]);
    }
    for (int i=1;i<=n;i++)printf("%d ",dp[i]);
}