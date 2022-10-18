#include <stdio.h>
#include <string.h> 
#include <queue>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Edge{
	int v,nxt;
}e[2000005];
int h[100005],cnt=2;
inline void addedge(int u,int v)
{
	e[cnt]=(Edge){v,h[u]};
	h[u]=cnt++;
}
int qwq[100005];
void dfs(int u,int d)
{
    qwq[d]++;
    for(int i=h[u];i;i=e[i].nxt)dfs(e[i].v,d+1);
}
signed main()
{
    int n=read();
    for(int i=2;i<=n;i++)
    {
        int x=read();
        addedge(x,i);
    }
    dfs(1,0);
    int ans=0;
    for(int i=0;i<=n;i++)ans+=(1&qwq[i]);
    printf("%lld\n",ans);
}