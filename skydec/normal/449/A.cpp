#include<stdio.h>
using namespace std;
typedef long long LL;
LL n,m,k;
LL max(LL &a,LL b)
{
          if(a<b)a=b;
}
LL min(LL a,LL b)
{
          return b;
}
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    LL ans=0;
    if(k>n-1+m-1)
    {
                 printf("-1\n");
                 return 0;
                 }
    if(k<=n-1)
    {
             max(ans,min(n%(k+1),n/(k+1))*m);
             }
    else max(ans,min(m%(k-n+1+1),m/(k-n+1+1)));
    
    LL tmp=n;n=m;m=tmp;
    if(k<=n-1)
    {
             max(ans,min(n%(k+1),n/(k+1))*m);
             }
    else max(ans,min(m%(k-n+1+1),m/(k-n+1+1)));
    printf("%I64d\n",ans);
    return 0;
}