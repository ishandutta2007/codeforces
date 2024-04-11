#include<stdio.h>
#include<iostream>
using namespace std;
typedef long double ld;
ld f[55][55][55];
long n,w;
long a[55];
ld jc[55];
long sum=0;
int main()
{
    scanf("%ld",&n);
    jc[0]=1;
    for(long i=1;i<=n;i++)
    {
             scanf("%ld",&a[i]);
             sum+=a[i];
             jc[i]=jc[i-1]*ld(i);
             }
    scanf("%ld",&w);
    if(sum<=w)
    {
              printf("%ld\n",n);
              return 0;
              }
    for(long i=1;i<=n;i++)f[0][0][i]=1;
    for(long i=1;i<=n;i++)
    for(long j=1;j<=n;j++)
    if(i!=j)
    {
            for(long k=n;k>=1;k--)
            for(long s=w;s>=a[i];s--)
            {
                     f[s][k][j]+=f[s-a[i]][k-1][j];
                     }
                     }
    ld ans=0;
    for(long i=1;i<=n;i++)
    {
             if(a[i]>w)a[i]=w+1;
             for(long j=w-a[i]+1;j<=w;j++)
             for(long k=1;k<=n;k++)
             ans+=f[j][k][i]*jc[k]*jc[n-k-1]*k;
             }
    ans/=jc[n];
    printf("%.7lf\n",(double)ans);
    return 0;
}