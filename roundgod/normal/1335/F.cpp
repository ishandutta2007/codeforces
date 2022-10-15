#include<bits/stdc++.h>
#define MAXN 1000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
string c[MAXN],mp[MAXN];
vector<int> G[MAXN],rG[MAXN];
int vis[MAXN];
int cnt[MAXN];
bool incyc[MAXN];
int ans,res;
vector<int> black;
void add_edge(int u,int v)
{
    G[u].push_back(v);
    rG[v].push_back(u);
}
int get_id(int x,int y)
{
    return x*m+y;
}
bool is_black(int id)
{
    int x=id/m;
    int y=id%m;
    if(c[x][y]=='0') return true; else return false;
}
void solve(int id)
{
    black.clear(); 
    int tot=0,cyc=0,cur=0;
    do
    {
        if(vis[id]!=-1) {cyc=tot+1-vis[id]; cur=id; break;}
        vis[id]=++tot;
        id=G[id][0];
    } 
    while(true);
    for(int i=0;i<cyc;i++) cnt[i]=0;
    tot=0;
    queue<int> que;
    int tmp=cur;
    do
    {
        vis[cur]=tot++;
        if(is_black(cur)) black.push_back(vis[cur]); 
        que.push(cur); incyc[cur]=true;
        cur=G[cur][0];
    } while (cur!=tmp);
    while(que.size())
    {
        int v=que.front();
        que.pop();
        for(auto to:rG[v])
        {
            if(incyc[to]) continue;
            vis[to]=(vis[v]-1+cyc)%cyc;
            if(is_black(to)) black.push_back(vis[to]);
            que.push(to);
        }
    }
    ans+=cyc;
    for(auto x:black) cnt[x]++;
    for(int i=0;i<cyc;i++) if(cnt[i]) res++;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans=0; res=0;
        for(int i=0;i<n;i++) cin>>c[i];
        for(int i=0;i<n;i++) cin>>mp[i];
        for(int i=0;i<n*m;i++) G[i].clear(),rG[i].clear();
        for(int i=0;i<n*m;i++) vis[i]=-1,incyc[i]=false;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(mp[i][j]=='L') add_edge(get_id(i,j),get_id(i,j-1));
                if(mp[i][j]=='R') add_edge(get_id(i,j),get_id(i,j+1));
                if(mp[i][j]=='U') add_edge(get_id(i,j),get_id(i-1,j));
                if(mp[i][j]=='D') add_edge(get_id(i,j),get_id(i+1,j));
            }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                int id=get_id(i,j);
                if(vis[id]==-1) solve(id);
            }
        printf("%d %d\n",ans,res);
    }
    return 0;
}