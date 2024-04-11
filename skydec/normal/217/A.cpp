#include<stdio.h>
#include<cstring>
using namespace std;
int fa[105];
int x[105],y[105];
int n;
int get(int p){if(p==fa[p])return p;return fa[p]=get(fa[p]);}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d%d",&x[i],&y[i]);fa[i]=i;}
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    if(x[i]==x[j]||y[i]==y[j])fa[get(i)]=get(j);
    int ans=0;
    for(int i=1;i<=n;i++)if(fa[i]==i)ans++;
    printf("%d\n",ans-1);
    return 0;
}