#include<stdio.h>
#include<cstring>
#define maxn 1002
using namespace std;
long a1[maxn][maxn],a2[maxn][maxn],a3[maxn][maxn],a4[maxn][maxn];
long n,m;long w[maxn][maxn];
#define max(a,b) ((a)>(b)?(a):(b))
void read(long &x)
{
     x=0;char p=getchar();
     while(!(p<='9'&&p>='0'))p=getchar();
     while(p<='9'&&p>='0')x*=10,x+=p-48,p=getchar();
}
int main()
{
    scanf("%ld%ld",&n,&m);
    for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
    read(w[i][j]);
    a1[1][1]=w[1][1];
    for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
    a1[i][j]=max(a1[i-1][j],a1[i][j-1])+w[i][j];
    a2[n][1]=w[n][1];
    for(long i=n;i>=1;i--)
    for(long j=1;j<=m;j++)
    a2[i][j]=max(a2[i+1][j],a2[i][j-1])+w[i][j];
    a3[n][m]=w[n][m];
    for(long i=n;i>=1;i--)
    for(long j=m;j>=1;j--)
    a3[i][j]=max(a3[i+1][j],a3[i][j+1])+w[i][j];
    for(long i=1;i<=n;i++)
    for(long j=m;j>=1;j--)
    a4[i][j]=max(a4[i][j+1],a4[i-1][j])+w[i][j];
    long ans=0;
    for(long i=2;i<=n-1;i++)
    for(long j=2;j<=m-1;j++)
    {
             long reu;
             reu=max(a4[i-1][j]+a3[i][j+1]+a2[i+1][j]+a1[i][j-1],a4[i][j+1]+a3[i+1][j]+a2[i][j-1]+a1[i-1][j]);
             ans=max(ans,reu);
             }
    printf("%ld\n",ans);
    return 0;
}