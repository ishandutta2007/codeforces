#include <queue>
#include <string.h> 
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#define int long long
inline int read()
{
	int num=0,f=1;char c=getchar();
	while(c<48||c>57){f=c=='-'?-1:f,c=getchar();}
	while(c>47&&c<58)num=num*10+(c^48),c=getchar();
	return num*f;
}
struct Edge{
    int v,nxt;
}e[5000005];
int cnt=1,h[200005];
int vis[200005],a[200005],dp[200005],deg[200005];
void addedge(int u,int v)
{
    e[cnt]=(Edge){v,h[u]};
    h[u]=cnt++;
    deg[v]++;
}
inline int max(int a,int b){return a>b?a:b;}
int tp()
{
    std::queue<int >q;
    vis[0]=0;q.push(0);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=h[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            deg[v]--;
            vis[v]=max(vis[u]+a[v],vis[v]);
            if(deg[v]==0)q.push(v);
        }
    }
    int ans=0;
    for(int i=0;i<=200000;i++)ans=max(ans,vis[i]);
    return ans;
}
signed main()
{
    int T=read();
    while(T--)
    {
        int n=read();
        memset(h,0,sizeof(h));
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        memset(deg,0,sizeof(deg));
        memset(vis,0,sizeof(vis));
        cnt=1;
        for(int i=0;i<n;i++)a[read()]++;
        for(int i=0;i<=200000;i++)
        {
            if(!a[i])continue;
            for(int j=i+i;j<=200000;j+=i)
            {
                if(a[j])addedge(i,j);
            }
        }
        for(int i=1;i<=200000;i++)addedge(0,i);
        printf("%lld\n",n-tp());
    }
}