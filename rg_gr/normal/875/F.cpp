#include <stdio.h>
#include <string.h> 
#include <algorithm>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
inline int bfs(int s,int t)
{
	return 0;
}
int fa[200005],sz[200005],h[200005];
int f(int x)
{
    return x==fa[x]?x:fa[x]=f(fa[x]);
}
#define e e114514
struct E{
    int u,v,w;
    bool operator<(const E& b)const
    {
        return w>b.w;
    }
}e[1000005];
signed main()
{
    int n=read(),m=read();
    int ans=0;
    int s=0,t=n+m+1,anss=0;
    for(int i=1;i<=n;i++)h[i]=1,fa[i]=i;
    //for(int i=1;i<=n;i++)addedge(s,i,0x3f3f3f3f3f3f3f3fll),addedge(i,s,0);
    for(int i=1;i<=m;i++)
    {
        int x=read(),y=read(),z=read();
        e[i].u=x,e[i].v=y,e[i].w=z;
        
    }
    std::sort(e+1,e+1+m);
    for(int i=1;i<=m;i++)
    {
        int x=f(e[i].u),y=f(e[i].v);
        if(x!=y&&(h[x]||h[y]))fa[x]=y,ans+=e[i].w,h[y]&=h[x];
        else if(x==y&&h[x])h[x]=0,ans+=e[i].w;
        //puts("A");
    }
    while(bfs(s,t))ans+=bfs(s,t);
    printf("%lld\n",ans);
	return 0;
}