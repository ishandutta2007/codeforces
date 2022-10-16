#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <bitset>
#include <map>
#include <algorithm>
#define int long long
inline int read()
{
    int num=0,f=1;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=(num<<3)+(num<<1)+(c^48),c=getchar();
    return num*f;
}
inline int min(int a,int b){return a<b?a:b;}
inline int max(int a,int b){return a>b?a:b;}
struct Edge{
    int v,nxt;
}e[200005];
int h[200005],cnt=1,deg[200005];
inline void addedge(int u,int v)
{
    e[cnt]=(Edge){v,h[u]};
    h[u]=cnt++;
}
int d[4][2]={1,0,0,1,-1,0,0,-1};
int px[555],py[555];
void dfs(int x,int y,int u,int f,int gap,int fa)
{
    int cur=0;
    px[u]=x;
    py[u]=y;
    for(int i=h[u];i;i=e[i].nxt)
    {
        if(e[i].v==fa)continue;
        if(cur==f)cur++;
        int nx=x+d[cur][0]*gap;
        int ny=d[cur][1]*gap+y;
        dfs(nx,ny,e[i].v,2^cur,gap>>1,u);
        cur++;
    }
}//
signed main()
{
    int n=read();
    for(int i=1;i<n;i++)
    {
        int x=read(),y=read();
        deg[x]++,deg[y]++;
        if(deg[x]>4||deg[y]>4){puts("NO");return 0;}
        addedge(x,y);
        addedge(y,x);
    }
    puts("YES");
    dfs(0,0,1,5,1ll<<(n+2),0);
    for(int i=1;i<=n;i++)printf("%lld %lld\n",px[i],py[i]);
    return 0;
}