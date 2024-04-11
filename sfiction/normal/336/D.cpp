/*
ID: Sfiction
OJ: CF
PROB: 336D
*/
/*
011
num[i]i01num[i]=C(n+m-i,m-1)final[i]
0..0(0*i)1XXX01final[i]=(i+1)%2101
0010010
m=0m=1num[1..n+1]
*/
#include <cstdio>
const int MAXN=100000;
const int MOD=1000000007;
void Exp(long long x,long long &s)
{
    long long n=MOD-2;
    for (;n;n>>=1)
    {
        if (n&1) s=(s*x)%MOD;
        x=(x*x)%MOD;
    }
}
int main()
{
    int n,m,g;
    int i,ans;
    long long f1,f2;
    scanf("%d%d%d",&n,&m,&g);
    if (m<2)
    {
        if (m==0) printf("%d",(n&1)!=g);
        else if (n&1) printf("%d",n/2+2*(!g));
            else printf("%d",n/2+g);
        return 0;
    }
    f1=1;
    ans=(n&1)==g;
    for (i=n;i;--i)
    {
        f2=f1;
        f1=(f2*(n+m-i))%MOD;
        Exp(n-i+1,f1);
        if ((i&1)!=g) ans=(ans+f1)%MOD;
    }
    printf("%d",ans);
    return 0;
}