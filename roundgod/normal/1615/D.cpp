#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int T,n,m;
vector<int> G[MAXN];
int p[MAXN],type[MAXN],r[MAXN];
int u[MAXN],v[MAXN],ans[MAXN];
map<P,int> mp,id;
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        r[i]=0;
        type[i]=0;
    }
}
P find(int x)
{
    if(p[x]==x) return P(0,x);
    else 
    {
        P pp=find(p[x]);
        return P(pp.F^type[x],pp.S);
    }
}
bool unite(int x,int y,int s)
{
    P px=find(x); P py=find(y);
    if(px.S==py.S) 
    {
        //puts("here");
        if((px.F^py.F)!=s) return false; else return true;
    }
    if(r[px.S]<r[py.S]) {p[px.S]=py.S; type[px.S]=(s^px.F^py.F); }
    else
    {
        p[py.S]=px.S; type[py.S]=(s^px.F^py.F);
        //printf("p[%d]=%d type[%d]=%d\n",py.S,p[py.S],py.S,type[py.S]);
        if(r[px.S]==r[py.S]) r[px.S]++;
    }
    return true;
}
void dfs(int v,int p)
{
    if(p!=0)
    {
        int x=v,y=p;
        if(mp.find(P(x,y))==mp.end()) swap(x,y);
        if(mp[P(x,y)]!=-1) ans[id[P(x,y)]]=mp[P(x,y)];
        else
        {
            ans[id[P(x,y)]]=find(v).F^find(p).F; 
        }
    }
    for(auto to:G[v])
    {
        if(to==p) continue;
        dfs(to,v);
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m); mp.clear(); id.clear();
        for(int i=1;i<=n;i++) G[i].clear();
        init(n);
        bool f=true;
        for(int i=0;i<n-1;i++)
        {
            int w;
            scanf("%d%d%d",&u[i],&v[i],&w);
            G[u[i]].push_back(v[i]); G[v[i]].push_back(u[i]);
            if(w!=-1) 
            {
                if(!unite(u[i],v[i],(__builtin_popcount(w)&1))) f=false;
                assert(f);
            }
            mp[P(u[i],v[i])]=w;
            id[P(u[i],v[i])]=i;
        }
        for(int i=0;i<m;i++)
        {
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            if(!unite(u,v,w)) f=false;
            //assert(f);
        }
        if(!f) {puts("NO"); continue;}
        puts("YES");
        dfs(1,0);
        for(int i=0;i<n-1;i++) printf("%d %d %d\n",u[i],v[i],ans[i]);
    }
    return 0;
}