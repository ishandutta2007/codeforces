#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int MAXN=200010;
int n,m,k;
struct edge
{
    int v;
    edge *next;
}*h[MAXN],pool[MAXN*2];
int top;
inline void addedge(int u,int v)
{
    edge *tmp=&pool[++top];tmp->v=v;tmp->next=h[u];h[u]=tmp;
    edge *pmt=&pool[++top];pmt->v=u;pmt->next=h[v];h[v]=pmt;
}
int vis[MAXN],seq[MAXN*2],pot;
void dfs(int u)
{
    seq[++pot]=u;
    vis[u]=1;
    for(edge *tmp=h[u];tmp;tmp=tmp->next)
    {
        if(!vis[tmp->v])
        {
            dfs(tmp->v);
            seq[++pot]=u;
        }
    }
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    if(n==1)
    {
        for(int i=1;i<=k;i++)
            printf("1 1\n");
        return 0;
    }
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        addedge(a,b);
    }
    dfs(1);
    --pot;
    int siz=pot/k+1,cur=0;
    for(int i=1;i<=k;i++)
    {
        if(pot<=cur)
        {
            printf("1 1\n");
            continue;
        }
        printf("%d ",min(pot-cur,siz));
        for(int j=cur+1;j<=pot&&j<=cur+siz;j++)
        {
            printf("%d ",seq[j]);
        }
        cur+=siz;
        printf("\n");
    }
    return 0;
}