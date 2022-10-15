#include<bits/stdc++.h>
#define MAXN 300005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,cnt;
vector<int> G[MAXN];
vector<int> ans;
bool vis[MAXN],chosen[MAXN],dead[MAXN];
int dist[MAXN];
vector<int> vec;
void dfs(int v)
{
    vis[v]=true; cnt++;
    for(auto to:G[v]) if(!vis[to]) dfs(to);
}
void update_chosen(int v)
{
    chosen[v]=true; ans.push_back(v);
    for(auto to:G[v])
    {
        assert(!chosen[to]);
        dead[to]=true;
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) G[i].clear(),vis[i]=false,chosen[i]=false,dead[i]=false;
        ans.clear(); vec.clear();
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v); G[v].push_back(u);
        }
        cnt=0;
        dfs(1);
        if(cnt!=n) {puts("NO"); continue;}
        puts("YES");
        for(int i=1;i<=n;i++) vis[i]=false;
        vis[1]=true;
        queue<int> que;
        que.push(1);
        while(que.size())
        {
            int v=que.front(); que.pop();
            if(!dead[v]&&!chosen[v]) update_chosen(v);
            for(auto to:G[v])
            {
                if(vis[to]) continue;
                vis[to]=true;
                que.push(to);
            }
        }
        printf("%d\n",ans.size());
        for(auto x:ans) printf("%d ",x);
        puts("");
    }
    return 0;
}