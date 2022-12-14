#include<stdio.h>
# include <bits/stdc++.h>
using namespace std;
long long GCD(long long a,long long b)
{
    if (a%b==0)return b;
    if (b%a==0)return a;
    return GCD(b%a,a);
}
int sum[1000000];
int a[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i],sum[i]=sum[i-1]+a[i];
    int ans=sum[n];
    if (ans==n)ans--;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            ans=max(ans,sum[i-1]+sum[n]-sum[j]+(j-i+1)-(sum[j]-sum[i-1]));
        }
    }
    cout<<ans<<endl;
}