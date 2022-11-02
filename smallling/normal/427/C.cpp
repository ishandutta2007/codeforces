#include<cstdio>
#include<cstring>

#define mo 1000000007
 
using namespace std;
  
struct lhy{
    int x,y,next;
}edge[500001];
  
int deap,stop,o,n,m,tot,son[100001],stap[100001],flag[100001],dfn[100001],low[100001],color[100001],flag1[100001],minn[100001],cost[100001],num[100001],k;
long long ans,ans1;
  
void add(int x,int y)
{
    edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}
  
void tarjan(int x)
{
    int j;
    dfn[x]=low[x]=++deap;
    flag[x]=1;
    stap[++stop]=x;
    for(int i=son[x];i;i=edge[i].next)
    {
        j=edge[i].y;
        if(!dfn[j])
        {
            tarjan(j);
            if(low[j]<low[x])
                low[x]=low[j];
        }
        else if(flag[j]&&dfn[j]<low[x])
            low[x]=dfn[j];
    }
    if(dfn[x]==low[x])
    {
        o++;
        do
        {
            j=stap[stop--];
            flag[j]=0;
            color[j]=o;
        }
        while(j!=x);
    }
}
  
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    	scanf("%d",&cost[i]);
    scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add(x,y);
    }
    for(int i=1;i<=n;i++)
    if(!dfn[i])
        tarjan(i);
    memset(minn,0x7f,sizeof(minn));
    for(int i=1;i<=n;i++)
    {
    	if(minn[color[i]]>cost[i])minn[color[i]]=cost[i],num[color[i]]=0;
    	if(minn[color[i]]==cost[i])num[color[i]]++;
    }
    ans1=1ll;
    for(int i=1;i<=o;i++)
    	ans+=1ll*minn[i],ans1=(1ll*ans1*num[i])%(1ll*mo);
    printf("%I64d %I64d",ans,ans1);
}