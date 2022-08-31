#include<stdio.h>
#include<cstring>
#include<cmath>
#define MAXN 2005
using namespace std;
typedef long double db;
typedef long long LL;
int f[MAXN][MAXN];int d[MAXN];
int n,k;
db fac[MAXN];
db calc(int a,int b)
{
            db res=fac[a];
            res-=fac[b];
            res-=fac[a-b];
            return res;
}
int main()
{
    scanf("%d%d",&n,&k);
    fac[0]=0;
    for(int i=1;i<=n;i++)fac[i]=fac[i-1]+logl((db)i);
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
            scanf("%d",&f[i][j]);
            f[j][i]=f[i][j];
            if(f[i][j]!=-1)
            d[i]++,d[j]++;
            }
    db fm=calc(n,k);
    db ans=0;
    for(int i=1;i<=n;i++)
    if(d[i]>=k)
    {
               LL sum=0;
               for(int j=1;j<=n;j++)
               if(f[i][j]!=-1)sum+=1ll*f[i][j];
               db xs=expl(calc(d[i]-1,k-1)-fm);
               ans+=xs*sum;
               }
    printf("%I64d\n",(long long)(ans+1e-8));
    return 0;
}