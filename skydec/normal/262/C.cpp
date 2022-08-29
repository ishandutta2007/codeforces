#include<stdio.h>
#include<algorithm>
#define MAXN 110000
using namespace std;
long sum[MAXN];
long n,k;
long min(long a,long b){if(a<b)return a;return b;}
long max(long a,long b){return a+b-min(a,b);}
int main()
{
    long m;
    scanf("%ld",&m);
    k=2100000;
    for(long i=1;i<=m;i++)
    {
             long a;scanf("%ld",&a);
             if(a<k)k=a;
             }
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)
    {
             scanf("%ld",&sum[i]);
             }
    sort(sum+1,sum+1+n);
    for(long i=1;i<=n;i++)sum[i]+=sum[i-1];
    long ans=0;
    for(long i=n;i>0;i-=k+2)
    {
             ans+=sum[i]-sum[max(i-k,0)];
             }
    printf("%ld\n",ans);
    return 0;
}