#include<stdio.h>
#define MAXN 110000
using namespace std;
typedef long long LL;
LL f[MAXN][2];
int cc[MAXN];
int n;
void MAX(LL &x,LL y){if(y>x)x=y;}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){int u;scanf("%d",&u);cc[u]++;}
    f[0][0]=0;
    for(int i=1;i<=100000;i++)
    {
            MAX(f[i][1],f[i-1][0]+cc[i]*1ll*i);
            MAX(f[i][0],f[i-1][0]);
            MAX(f[i][0],f[i-1][1]);
            }
    LL ans=f[100000][1];
    MAX(ans,f[100000][0]);
    printf("%I64d\n",ans);
    return 0;
}