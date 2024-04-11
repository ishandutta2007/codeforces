#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
vector<int> G[MAXN];
int p[MAXN];
int h[MAXN];
int s[MAXN];
bool f;
void dfs(int v,int fa)
{
    s[v]=p[v];
    for(auto to:G[v])
    {
        if(to==fa) continue;
        dfs(to,v);
        s[v]+=s[to];
    }
}
void dfs2(int v,int fa)
{
    int sum=0;
    for(auto to:G[v])
    {
        if(to==fa) continue;
        dfs2(to,v);
        sum+=s[to];
    }
    if(s[v]-sum>p[v]) f=false;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear();
        for(int i=1;i<=n;i++) scanf("%d",&p[i]);
        for(int i=1;i<=n;i++) scanf("%d",&h[i]);
        for(int i=0;i<n-1;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y); G[y].push_back(x);
        }
        dfs(1,0);
        f=true;
        for(int i=1;i<=n;i++)
        {
            if((s[i]+h[i])&1) f=false;
            if(h[i]>s[i]||h[i]<-s[i]) f=false;
            s[i]=(s[i]-h[i])/2;
        }
        dfs2(1,0);
        if(f) puts("YES"); else puts("NO");
    }
    return 0;
}