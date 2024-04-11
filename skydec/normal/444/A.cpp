#include<stdio.h>
#define MAXN 505
using namespace std;
int v[MAXN];
int main()
{
    double ans=0;
    int n,m;scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
            scanf("%d",&v[i]);
            }
    for(int i=1;i<=m;i++)
    {
            int a,b,c;scanf("%d%d%d",&a,&b,&c);
            if(((v[a]+v[b])*1.)/c>ans)ans=((v[a]+v[b])*1.)/c;
            }
    printf("%.15lf\n",ans);
    return 0;
}