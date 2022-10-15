#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k;
vector<int> d[MAXN];
string str;
int f[MAXN],g[MAXN],par[MAXN];
ll ans=0;
int fa[MAXN],r[MAXN];
vector<int> v;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
        r[i]=0;
        f[i]=0;
        g[i]=1;
        par[i]=0;
    }
}
P find(int x)
{
    if(fa[x]==x) return P(x,0);
    else 
    {
        P p=find(fa[x]);
        p.S^=par[x];
        return p;
    }
}
void unite(int x,int y,int flag)
{
    P p=find(x);
    P q=find(y);
    x=p.F; y=q.F;
    if(x==y) return;
    ans-=min(f[x],g[x]); ans-=min(f[y],g[y]);
    flag^=p.S; flag^=q.S;
    if(r[x]<r[y]) 
    {
        fa[x]=y;
        if(!flag) {f[y]=min(INF,f[x]+f[y]); g[y]=min(INF,g[x]+g[y]);}
        else {f[y]=min(INF,f[y]+g[x]); g[y]=min(INF,g[y]+f[x]);}
        ans+=min(f[y],g[y]);
        par[x]^=flag;
    }
    else
    {
        if(!flag) {f[x]=min(INF,f[x]+f[y]); g[x]=min(INF,g[x]+g[y]);}
        else {f[x]=min(INF,f[x]+g[y]); g[x]=min(INF,g[x]+f[y]);}
        ans+=min(f[x],g[x]);
        fa[y]=x; par[y]^=flag;
        if(r[x]==r[y]) r[x]++;
    }
}
void st(int x,int flag)
{
    P p=find(x);
    flag^=p.S;
    x=p.F;
    ans-=min(f[x],g[x]);
    if(flag) f[x]=INF; else g[x]=INF;
    ans+=min(f[x],g[x]);
}
bool same(int x,int y)
{
    return find(x)==find(y);
}
int main()
{
    scanf("%d%d",&n,&k);
    cin>>str;
    for(int i=1;i<=k;i++)
    {
        v.clear();
        int x;
        scanf("%d",&x);
        for(int i=0;i<x;i++)
        {
            int y;
            scanf("%d",&y);
            v.push_back(y);
        }
        for(auto pos:v) d[pos].push_back(i);
    }
    init(k);
    for(int i=1;i<=n;i++)
    {
        if(d[i].size()==1)
        {
            if(str[i-1]=='1') st(d[i][0],0); else st(d[i][0],1);
        } 
        else if(d[i].size()==2)
        {
            if(str[i-1]=='1') unite(d[i][0],d[i][1],0); else unite(d[i][0],d[i][1],1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}