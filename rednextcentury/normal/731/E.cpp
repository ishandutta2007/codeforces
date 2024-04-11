#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long dp[1000000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],a[i]+=a[i-1];
    dp[n]=0;
    long long mx=a[n]-dp[n];
    for (int i=n-1;i>=0;i--)
    {
        dp[i]=mx;
        mx=max(mx,a[i]-dp[i]);
    }
    cout<<dp[1]<<endl;
}