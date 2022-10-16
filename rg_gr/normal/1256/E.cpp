#include <stdio.h>
#include <string.h>
#include <algorithm>
#define int long long
inline int read()
{
    int f=1,num=0;char c=getchar();
    while(c<48||c>57){if(c=='-')f=-1;c=getchar();}
    while(c>47&&c<58)num=num*10+(c^48),c=getchar();
    return num*f;
}
inline int re1d()
{
    char c=getchar();
    while (c<48||c>49)
    {
        c=getchar();
    }
    return c&1;
    
}
inline int max(int a,int b)
{
    return a<b?a:b;
}
struct qwq{
    int d,i;
    bool operator<(const qwq& b)const
    {
        return d<b.d;
    }
}
 a[1000005];int vis[1000005];
int aa[1000005],cnt,bel[1000005];
void dfs(int n)
{
    if(n==0)return;
    if(n<=5)
    {
        cnt++;
        for(int i=1;i<=n;i++)aa[i]=cnt;
        return;
    }
    if(vis[n]==vis[n-3]+a[n].d-a[n-2].d){aa[n-2]=aa[n-1]=aa[n]=++cnt;dfs(n-3);}
    else if(vis[n]==vis[n-4]+a[n].d-a[n-3].d){aa[n-3]=aa[n-2]=aa[n-1]=aa[n]=++cnt;dfs(n-4);}
    else if(vis[n]==vis[n-5]+a[n].d-a[n-4].d){aa[n-4]=aa[n-3]=aa[n-2]=aa[n-1]=aa[n]=++cnt;dfs(n-5);}
}
signed main()
{
    int n=read();
    for(int i=1;i<=n;i++)a[i].d=read(),a[i].i=i;
    std::sort(a+1,a+1+n);
    memset(vis,0x3f,sizeof(vis));
    //vis[0]=vis[1]=vis[2]=0x3f3f3f3f3f3f3f3fll;
    vis[3]=a[3].d-a[1].d;
    vis[4]=a[4].d-a[1].d;
    vis[5]=a[5].d-a[1].d;
    for(int i=6;i<=n;i++)
    {
        vis[i]=max(vis[i-3]+a[i].d-a[i-2].d,vis[i]),
        vis[i]=max(vis[i-5]+a[i].d-a[i-4].d,vis[i]),
        vis[i]=max(vis[i-4]+a[i].d-a[i-3].d,vis[i]);
    }
    printf("%lld ",vis[n]);
    dfs(n);
    printf("%lld\n",cnt);
    for(int i=1;i<=n;i++)bel[a[i].i]=aa[i];
    for(int i=1;i<=n;i++)printf("%lld ",bel[i]);
}