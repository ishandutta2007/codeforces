#include<iostream>
#define MIN -100000000000000000

using namespace std;

long long m,n,dp[5001][5001],sum[5001],a[5001];
bool b[5001][5001];

long long solve(long long br, long long k)
{
    if(k==0)
    {
        return 0;
    }
    if(br>=n-m+1)return MIN;
    if(b[br][k]==1)return dp[br][k];

    b[br][k]=1;

    dp[br][k]=max(solve(br+1,k),solve(br+m,k-1)+sum[br]);

    return dp[br][k];
}

int main ()
{
    long long k,i;

    ios::sync_with_stdio(false);

    cin>>n>>m>>k;

    for(i=0;i<n;i++)cin>>a[i];

    for(i=0;i<m;i++)sum[0]+=a[i];

    for(i=1;i<n-m+1;i++)
    {
        sum[i]=sum[i-1]-a[i-1]+a[i+m-1];
    }

    cout<<solve(0,k)<<endl;

    return 0;
}