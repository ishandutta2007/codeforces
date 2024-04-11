#include<stdio.h>
#define MAXN 110000
using namespace std;
int head[MAXN*2],next[MAXN*2],p[MAXN*2],fa[MAXN];int tot=0;
double ans=0;
void l(int a,int b){tot++;p[tot]=b;next[tot]=head[a];head[a]=tot;}
void dfs(int x,int dep)
{
     ans+=1./dep;
     for(int u=head[x];u;u=next[u])if(p[u]!=fa[x])fa[p[u]]=x,dfs(p[u],dep+1);
}
int n;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++){int a,b;scanf("%d%d",&a,&b);l(a,b);l(b,a);}
    dfs(1,1);printf("%.7lf\n",ans);
    return 0;
}