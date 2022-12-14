#include<bits/stdc++.h>
using namespace std;
struct inter
{
    int l,r;
};
bool operator<(inter A,inter B)
{
    return A.r<B.r;
}
inter a[1000000];
int dp[1000000];
int bs(int l,int r,int X)
{
    int ret=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if (a[mid].r<=X)
            ret=mid,l=mid+1;
        else r=mid-1;
    }
    return ret;
}
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,w;
        cin>>x>>w;
        a[i].l=x-w,a[i].r=x+w;
    }
    sort(a+1,a+n+1);
    dp[0]=0;
    for (int i=1;i<=n;i++)
    {
        int j=bs(1,i-1,a[i].l);
        dp[i]=max(dp[i],dp[j]+1);
        dp[i]=max(dp[i],dp[i-1]);
    }
    cout<<dp[n]<<endl;
}