#include <stdio.h>
#include <string.h>
#define odl(x) printf("%d\n",x)
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Edge{
	int v,nxt;
}e[10000005];
int h[10000005],cnt=1;
inline void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int buf[10000005],ans[10000005],dep[10000005],son[10000005];
int *f[10000005],*g[10000005],*now=buf;
void dfs(int u,int fa=0)
{
	for(int i=h[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v==fa)continue;
		dfs(v,u);
		if(dep[v]>dep[son[u]])son[u]=v;
	}
	dep[u]=dep[son[u]]+1;
}
void dfs2(int u,int fa=0)
{
    f[u][0]=1;
    if(son[u])
    {
        f[son[u]]=f[u]+1;
        dfs2(son[u],u);
        ans[u]=ans[son[u]]+1;
        if(f[u][ans[u]]==1)ans[u]=0;
    }
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if (v==son[u]||v==fa)continue;
        f[v]=now;now+=dep[v];
        dfs2(v,u);
        for (int i=1;i<=dep[v];i++)
        {
            f[u][i]+=f[v][i-1];
            if(f[u][i]>f[u][ans[u]]||(f[u][i]==f[u][ans[u]]&&i<ans[u]))ans[u]=i;
        }
    }
}
signed main()
{
	int n=read();
	for(int i=2;i<=n;i++){int x=read(),y=read();addedge(x,y);addedge(y,x);}
	dfs(1);f[1]=now,now+=dep[1];
	dfs2(1);
	for(int i=1;i<=n;i++)odl(ans[i]);
	return 0;
}