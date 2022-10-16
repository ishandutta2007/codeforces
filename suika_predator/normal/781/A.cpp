#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int n,m;
int deg[200010],cnt[200010],ans[200010],maxx;
struct edge
{
    int v;
    edge *next;
}*h[200010],pool[400020];
int top;
inline void addedge(int u,int v)
{
    edge *tmp=&pool[++top];tmp->v=v;tmp->next=h[u];h[u]=tmp;++deg[u];
    edge *pmt=&pool[++top];pmt->v=u;pmt->next=h[v];h[v]=pmt;++deg[v];
}
void dfs(int u,int pa)
{
    ans[u]=++cnt[pa];
    for(edge *tmp=h[u];tmp;tmp=tmp->next)
    {
        while(cnt[pa]+1==ans[u]||cnt[pa]+1==ans[pa])++cnt[pa];
        while(cnt[u]+1==ans[u]||cnt[u]+1==ans[pa])++cnt[u];
        if(tmp->v!=pa)
        {
            dfs(tmp->v,u);
        }
    }
}
int main()
{
    scanf("%d",&n);
    int a,b;
    for(int i=1;i<n;++i)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b);
        if(deg[a]>maxx)maxx=deg[a];
        if(deg[b]>maxx)maxx=deg[b];
    }
    dfs(1,0);
    printf("%d\n",maxx+1);
    for(int i=1;i<=n;++i)printf("%d ",ans[i]);
    return 0;
}