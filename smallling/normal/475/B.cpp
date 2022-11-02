#include<cstdio>
#include<cstring>

using namespace std;
 
struct lhy{
    int x,y,next;
}edge[50001];
 
int b[10010],a[30][30],num,deap,stop,o,n,m,tot,son[10001],stap[10001],flag[10001],dfn[10001],low[10001],color[10001],flag1[10001],k;
 
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
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=++num;
    for(int i=1;i<=n;i++)
    {
        char ch=getchar();
        while(ch!='<'&&ch!='>')ch=getchar();
        if(ch=='>')
            for(int j=1;j<m;j++)
                add(a[i][j],a[i][j+1]);
        else
            for(int j=m;j>1;j--)
                add(a[i][j],a[i][j-1]);
    }
    for(int i=1;i<=m;i++)
    {
        char ch=getchar();
        while(ch!='^'&&ch!='v')ch=getchar();
        if(ch=='v')
            for(int j=1;j<n;j++)
                add(a[j][i],a[j+1][i]);
        else
            for(int j=n;j>1;j--)
                add(a[j][i],a[j-1][i]);     
    }
    n=num;
    for(int i=1;i<=n;i++)
        if(!dfn[i])
            tarjan(i);
    b[color[1]]=1;
    for(int i=2;i<=n;i++)
        if(!b[color[i]])
        {
            puts("NO");
            return 0;
        }
    puts("YES");
}