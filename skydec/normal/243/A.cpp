#include<stdio.h>
#include<cstring>
#define MAXN 110000
using namespace std;
long n;
long a[MAXN];
bool flag[MAXN*20]={false};
long g[MAXN][2];
int main()
{
    scanf("%ld",&n);
    for(long i=1;i<=n;i++)
    {
             scanf("%ld",&a[i]);
             }
    long now=0;
    for(long i=1;i<=n;i++)
    {
             now^=1;
             g[i][now]=a[i];
             flag[a[i]]=1;
             //if(g[i][now]==g[i][now^1])continue;
             for(long j=i-1;j>=1;j--)
             {
                      g[j][now]=g[j+1][now]|a[j];
                      if(g[j][now]==g[j][now^1])break;
                      flag[g[j][now]]=1;
                      }
                      }
    long ans=0;
    for(long i=0;i<=2000000;i++)ans+=flag[i];
    printf("%ld\n",ans);
    return 0;
}