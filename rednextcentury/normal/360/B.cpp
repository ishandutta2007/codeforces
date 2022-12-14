#include <bits/stdc++.h>
using namespace std;
int a[1000000];
int dp[2001];
int n,k;
bool check(long long m)
{
    dp[1]=0;
    int mn=k+1;
    for (int i=2;i<=n;i++)
    {
        dp[i]=i-1;
        for (int j=1;j<i;j++)
        {
            if (abs(a[i]-a[j])<=(i-j)*m)
                dp[i]=min(dp[i],dp[j]+(i-j-1));
        }
        mn=min(mn,dp[i]+(n-i));
    }
    return mn<=k;
}
long long bs(long long l,long long r)
{
    int ret=0;
    while(l<=r)
    {
        long long mid=(l+r)/2;
        if (check(mid))
            ret=mid,r=mid-1;
        else l=mid+1;
    }
    return ret;
}
int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    check(0);
    long long ret=bs(0,2000000000);
    cout<<ret<<endl;

}