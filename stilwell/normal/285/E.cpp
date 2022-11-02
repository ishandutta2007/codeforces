#include <stdio.h>
#include <stdlib.h>
#define p 1000000007
using namespace std;

int n,m,i,j,k;
int f[1005][1005][4],fac[1005],C[1005][1005],ans[1005];

void add(int &a,int b){a+=b;if(a>=p)a-=p;}

int main()
{
    scanf("%d%d",&n,&m);
    fac[0]=1;
    for(i=1;i<=n;++i)fac[i]=(long long)fac[i-1]*i%p;
    C[0][0]=1;
    for(i=0;i<=n;++i)
    for(j=0;j<=i;++j)
    {
        if(C[i][j]>=p)C[i][j]-=p;
        C[i+1][j]+=C[i][j];
        C[i+1][j+1]+=C[i][j];
    }
    f[1][0][1]=1;
    for(i=1;i<=n;++i)
    for(j=0;j<i;++j)
    for(k=0;k<4;++k)
    if(f[i][j][k])
    {
        add(f[i+1][j][k>>1],f[i][j][k]);
        if(!(k&1))add(f[i+1][j+1][k>>1],f[i][j][k]);
        if(i!=n)add(f[i+1][j+1][(k>>1)+2],f[i][j][k]);
    }
    for(i=0;i<=n;++i)
    {
        for(j=0;j<4;++j)add(ans[i],f[n+1][i][j]);
        ans[i]=(long long)ans[i]*fac[n-i]%p;
    }
    for(i=n;i>=0;--i)
    for(j=i+1;j<=n;++j)
    add(ans[i],p-(long long)ans[j]*C[j][i]%p);
    printf("%d\n",ans[m]);
}