#include<bits/stdc++.h>
#define MAXN 820000
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n1,n2,m,q;
map<P,int> mp;
vector<int> G[MAXN];
int mx[MAXN],my[MAXN];
queue<int> que;
int dx[MAXN],dy[MAXN];
bool removed[MAXN];
bool vis[MAXN];
vector<int> cover;
void dfs(int v)
{
    assert(!vis[v]);
    vis[v]=true;
    if(v<=n1) 
    {
        //assert(!mx[v]); 
        for(auto to:G[v]) if(!vis[to]&&to!=mx[v]) dfs(to);
    }
    else 
    {
        assert(my[v]);
        dfs(my[v]);
    }
}
bool find(int u)
{
    for(int i=0;i<G[u].size();i++)
    {
        if(!vis[G[u][i]]&&dy[G[u][i]]==dx[u]+1)
        {
            vis[G[u][i]]=true;
            if(!my[G[u][i]]||find(my[G[u][i]]))
            {
                mx[u]=G[u][i];
                my[G[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}
ll matching()
{
    memset(mx,0,sizeof(mx));
    memset(my,0,sizeof(my));
    ll ans=0;
    while(true)
    {
        bool flag=false;
        while(!que.empty()) que.pop();
        memset(dx,0,sizeof(dx));
        memset(dy,0,sizeof(dy));
        for(int i=1;i<=n1;i++)
        {
            if(removed[i]) continue;
            if(!mx[i]) que.push(i);
        }
        while(!que.empty())
        {
            int u=que.front();
            que.pop();
            for(int i=0;i<G[u].size();i++)
            {
                if(removed[G[u][i]]) continue;
                if(!dy[G[u][i]])
                {
                    dy[G[u][i]]=dx[u]+1;
                    if(my[G[u][i]])
                    {
                        dx[my[G[u][i]]]=dy[G[u][i]]+1;
                        que.push(my[G[u][i]]);
                    }
                    else flag=true;
                }
            }
        }
        if(!flag) break;
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n1;i++)
            if(!mx[i]) find(i); 
    }
    for(int i=1;i<=n1;i++)
        if(mx[i]) ans+=mp[P(i,mx[i])];
    return ans;
}
void find_cover()
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n1;i++)
        if(!mx[i]) dfs(i);
    for(int i=1;i<=n1;i++) if(!vis[i]) cover.push_back(i);
    for(int i=n1+1;i<=n1+n2;i++) if(vis[i]) cover.push_back(i);
}
vector<int> calc_edges()
{
    vector<int> edges;
    for(int i=1;i<=n1;i++)
    {
        if(removed[i]||removed[mx[i]]) continue;
        if(mx[i]) edges.push_back(mp[P(i,mx[i])]);
    }
    sort(edges.begin(),edges.end());
    return edges;
}
int main()
{
    scanf("%d%d%d%d",&n1,&n2,&m,&q);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        G[x].push_back(n1+y); G[n1+y].push_back(x);
        mp[P(x,n1+y)]=mp[P(n1+y,x)]=i;
    }
    memset(removed,false,sizeof(removed));
    ll ans=matching(); find_cover();
    for(int i=0;i<q;i++)
    {
        int type;
        scanf("%d",&type);
        if(type==1)
        {
            assert(cover.size());
            printf("%d\n",1);
            int x=cover.back();
            if(x<=n1) printf("%d\n",x); else printf("%d\n",-(x-n1));
            removed[x]=true;
            cover.pop_back();
            if(x<=n1) 
            {
                assert(mx[x]); assert(!removed[mx[x]]);
                ans-=mp[P(x,mx[x])]; 
                mx[x]=my[mx[x]]=0;
            }else 
            {
                assert(my[x]);
                ans-=mp[P(my[x],x)];
                my[x]=mx[my[x]]=0;
            }
            printf("%lld\n",ans);
            fflush(stdout);
        }
        else
        {
            auto edges=calc_edges();
            printf("%d\n",(int)edges.size()); 
            for(auto x:edges) printf("%d ",x);
            printf("\n");
            fflush(stdout);
        }
    }
    return 0;
}