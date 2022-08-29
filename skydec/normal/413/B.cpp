#include<stdio.h>
using namespace std;
long chat[15];
bool lis[21000][15]={false};
long k,n,m;long ans[21000]={0};
int main()
{
    scanf("%ld%ld%ld",&n,&m,&k);
    for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
    {
             long s;scanf("%ld",&s);
             lis[i][j]=s;
             }
    for(long i=1;i<=k;i++)
    {
             long x,y;scanf("%ld%ld",&x,&y);
             chat[y]++;
             ans[x]--;
             }
    for(long i=1;i<=n;i++)
    for(long j=1;j<=m;j++)
    if(lis[i][j])ans[i]+=chat[j];
    for(long i=1;i<=n-1;i++)printf("%ld ",ans[i]);printf("%ld\n",ans[n]);
    return 0;
}