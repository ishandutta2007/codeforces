#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 2e5 + 11;

int a[N],b[N];
int n;
int dp[N][2];

bool good(int x)
{
    int f0=0,f1=0;

    for (int j=0; j<=n; j++)
        dp[j][0]=dp[j][1]=0;
    dp[0][0]=f0;
    dp[0][1]=f1;
    for (int i=0; i<n; i++)
    {
        if (dp[i][0]<=0) dp[i][1]=-x; else
        if (dp[i][0]<x) dp[i][1]=min(dp[i][1],-1); else
        return false;
        dp[i+1][0]=a[i+1]-a[i]+dp[i][1];
        if (dp[i][0]>0&&a[i+1]-x<a[i]-dp[i][0]) dp[i+1][1]=a[i+1]-a[i]-x;
    }
    if (dp[n][0]<=0) dp[n][1]-=x; else
    if (dp[n][0]<x) dp[n][1]=min(dp[n][1],-1); else return false;
    if (dp[n][0]<=f0&&dp[n][1]<=f1) return true;

    f0=dp[n][0]; f1=dp[n][1];

    for (int j=0; j<=n; j++)
        dp[j][0]=dp[j][1]=0;
    dp[0][0]=f0;
    dp[0][1]=f1;
    for (int i=0; i<n; i++)
    {
        if (dp[i][0]<=0) dp[i][1]=-x; else
        if (dp[i][0]<x) dp[i][1]=min(dp[i][1],-1); else
        return false;
        dp[i+1][0]=a[i+1]-a[i]+dp[i][1];
        if (dp[i][0]>0&&a[i+1]-x<a[i]-dp[i][0]) dp[i+1][1]=a[i+1]-a[i]-x;
    }
    if (dp[n][0]<=0) dp[n][1]-=x; else
    if (dp[n][0]<x) dp[n][1]=min(dp[n][1],-1); else return false;
    if (dp[n][0]<=f0&&dp[n][1]<=f1) return true;

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin>>m>>n;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    int pos=1,mx=m-a[n]+a[1];
    for (int i=2; i<=n; i++)
        if (a[i]-a[i-1]>mx) {mx=a[i]-a[i-1]; pos=i;}
    for (int i=1; i<=n; i++)
        if (i+pos-1<=n) b[i]=a[i+pos-1]; else b[i]=a[i+pos-n-1]+m;
    for (int i=1; i<=n; i++)
        a[i]=b[i];
    a[0]=a[n]-m;
    int l=0,r=mx;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        if (good(mid)) r=mid; else l=mid;
    }
    if (good(l)) r=l;
    cout<<r-1;
}