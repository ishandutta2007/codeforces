#include<cstdio>

#define mo 1000000007

using namespace std;

struct lhy{
    int x,y,next;
}edge[400040];

int f[200020],son[200020],fa[200020],A[200020];
int cnt,n,x,tot,ff[200020],ans[200020],L[200020],R[200020];

inline void add(int x,int y)
{
    edge[++tot].x=x;edge[tot].y=y;edge[tot].next=son[x];son[x]=tot;
}

void dfs(int x)
{
    f[x]=1;
    for(int i=son[x];i;i=edge[i].next)
        if(edge[i].y!=fa[x])
        {
            fa[edge[i].y]=x;
            dfs(edge[i].y);
            f[x]=1ll*f[x]*(1+f[edge[i].y])%mo;
        }
}

void Dfs(int x)
{
    ans[x]=1ll*f[x]*ff[x]%mo;
    A[0]=0;
    L[0]=1;
    for(int i=son[x];i;i=edge[i].next)if(edge[i].y!=fa[x])A[++A[0]]=edge[i].y;
    R[A[0]+1]=1;
    for(int i=1;i<=A[0];i++)L[i]=1ll*L[i-1]*(1+f[A[i]])%mo;
    for(int i=A[0];i;i--)R[i]=1ll*R[i+1]*(1+f[A[i]])%mo;
    cnt=0;
    for(int i=son[x];i;i=edge[i].next)
        if(edge[i].y!=fa[x])
        {
            cnt++;
            ff[edge[i].y]=1ll*ff[x]*L[cnt-1]%mo*R[cnt+1]%mo;
            ff[edge[i].y]++;
        }
    for(int i=son[x];i;i=edge[i].next)
        if(edge[i].y!=fa[x])Dfs(edge[i].y);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&x);
        add(i+1,x),add(x,i+1);
    }
    ff[1]=1;
    dfs(1);
    Dfs(1);
    for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}