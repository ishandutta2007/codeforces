#include <bits/stdc++.h>
using namespace std;
long long n,x,a[100001];
signed main()
{
    cin>>n>>x;
    long long mn=9e18;
    for (long long i = 1; i <= n; ++i)
    {
        cin>>a[i];
        if (a[i]<mn)
        {
            mn=a[i];
        }
    }
    for (long long i = 1; i <= n; ++i)
    {
        a[i]-=mn;
    }
    long long now=x,sum=mn*n;
    while(1)
    {
        if (a[now]==0)
        {
            a[now]+=sum;
            for (long long i = 1; i <= n; ++i)
            {
               cout<<a[i]<<' ';
            }
            return 0;
        }
        --a[now];
        ++sum;
        now=now==1?n:now-1;
    }
    return 0;
}