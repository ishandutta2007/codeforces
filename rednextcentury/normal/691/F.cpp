#include<bits/stdc++.h>
using namespace std;
long long a[5000000];
long long ret[5000000];
int main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x]++;
    }
    int mx = 3e6;
    for (int i=1;i<=mx;i++)
    {
        for (int j=i;j<=mx;j+=i)
        {
            if (i==j/i)
                ret[j]+=a[i]*(a[i]-1);
            else
                ret[j]+=(a[j/i])*(a[i]);
        }
    }
    long long tot = n*1LL*(n-1);
    long long sum=0;
    for (int i=1;i<=mx;i++)
        ret[i]+=ret[i-1];
    sum = tot;
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int x;
        scanf("%d",&x);
        printf("%lld\n",sum-ret[x-1]);
    }
}