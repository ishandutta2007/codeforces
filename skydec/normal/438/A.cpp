#include<stdio.h>
using namespace std;
bool f[1005][1005];
bool top[1005][1005];
long n,m;
long rd[1005];
long v[1005];
int main()
{
    scanf("%ld%ld",&n,&m);
    long long ans=0;
    for(long i=1;i<=n;i++)scanf("%ld",&v[i]);
    for(long i=1;i<=m;i++)
    {
             long x,y;scanf("%ld%ld",&x,&y);
             if(v[x]>v[y])ans+=v[y];else ans+=v[x];
             }
    printf("%I64d\n",ans);
    return 0;
}