/*
ID: Sfiction
OJ: CF
PROB: 341C
*/
#include <cstdio>
#include <cstring>
const long long MOD=1000000007;
const int MAXN=2000;
int a[MAXN+1];
long long f[MAXN*2][MAXN+1];
long long Find(int m,int k)
{
    if (f[m][k]<0)
    {
        f[m][k]=(Find(m,k-1)*m)%MOD;
        f[m][k]=(Find(m+1,k-2)*(k-1)+f[m][k])%MOD;
    }
    return f[m][k];
}
int main()
{
    int i;
    int n,m,k;
    scanf("%d",&n);
    for (i=1;i<=n;++i) scanf("%d",&a[i]);
    m=k=0;
    for (i=1;i<=n;++i)
        if (a[i]<0) ++m;
        else if (a[a[i]]<0) ++k;
    k=m-k;
    m-=k;
    memset(f,-1,sizeof(f));
    f[0][0]=1;
    f[0][1]=0;
    for (i=1;i<=(n<<1);++i)
    {
        f[i][0]=(f[i-1][0]*i)%MOD;
        f[i][1]=(f[i][0]*i)%MOD;
    }
    printf("%I64d",Find(m,k));
    return 0;
}