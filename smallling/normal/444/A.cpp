#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,a[601];
double ans;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v,l;
        scanf("%d%d%d",&u,&v,&l);
        ans=max(ans,(double)(a[u]+a[v])/l);
    }
    printf("%.10lf",ans);
}