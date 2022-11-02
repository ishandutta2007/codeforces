#include<bits/stdc++.h>
#define N 400005
using namespace std;
int n,to[N<<1],hd[N<<1],lk[N],cnt,rt,sz[N],mx,sec;
bool ans[N];
inline void add(int u,int v)
{to[++cnt]=v,hd[cnt]=lk[u],lk[u]=cnt;}
int ini(int x,int fr)
{
    register int tmp;
    sz[x]=1;
    for(int s,i=lk[x];i;i=hd[i])
    if((s=to[i])^fr)
    {
        tmp=ini(s,x);sz[x]+=sz[s];
        if(sz[s]>(n>>1))return tmp;
        if(sz[s]==(n>>1)&&!(n&1))
        {
            for(int j=0;j<n;j++)
            printf("1 ");
            exit(0);
        }
    }
    return x;
}
void dfs(int x,int fr)
{
    sz[x]=1;
    for(int s,i=lk[x];i;i=hd[i])
    if((s=to[i])^fr)
    {
        dfs(s,x);sz[x]+=sz[s];
    }
}
void dfss(int x,int fr,int nn)
{
    if(n-sz[x]-nn<=n>>1)ans[x]=1;
    for(int s,i=lk[x];i;i=hd[i])
    if((s=to[i])^fr)
    dfss(s,x,nn);
}
int u,v;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
    {
        scanf("%d%d",&u,&v),
        add(u,v),add(v,u);
    }
    rt=ini(1,0);
    dfs(rt,0);
    for(int i=lk[rt];i;i=hd[i])
    if(sz[to[i]]>=mx)
    sec=mx,mx=sz[to[i]];
    else if(sz[to[i]]>sec)sec=sz[to[i]];
    for(int i=lk[rt];i;i=hd[i])
    if(sz[to[i]]==mx)dfss(to[i],rt,sec);
    else dfss(to[i],rt,mx);ans[rt]=1;
    for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
}