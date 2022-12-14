# include <iostream>
# include <vector>
using namespace std;
int o=1;
int disc[1000000];
int low[1000000];
int num=0;
bool vis[1000000],viss[1000000],viss2[1000000];
vector<int> adja[1000000];
vector<int> adj[1000000];
vector<int> bridge[1000000];
int pa[1000000];
bool br[1000000];
void get_bridges(int v)
{
    disc[v]=low[v]=o;
    o++;
    vis[v]=1;
    int n=adja[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adja[v][i];
        if (vis[u])
        {
            if (u!=pa[v])
                low[v]=min(low[v],disc[u]);
            continue;
        }
        pa[u]=v;
        get_bridges(u);
        low[v]=min(low[v],low[u]);
        if (low[u]>disc[v])
            num++,bridge[v][i]=1,br[u]=1;
    }
}
int comp[1000000];
void dfss(int v, int col)
{
    comp[v]=col;
    viss[v]=1;
    int n=adja[v].size();
    for (int i=0; i<n; i++)
    {
        int u= adja[v][i];
        if (viss[u]) continue;
        if (bridge[v][i])
            continue;
        dfss(u,col);
    }
}
void dfss2(int v)
{
    viss2[v]=1;
    int n=adja[v].size();
    for (int i=0; i<n; i++)
    {
        int u= adja[v][i];
        if (viss2[u]) continue;
        if (bridge[v][i]) adj[comp[v]].push_back(comp[u]),adj[comp[u]].push_back(comp[v]);
        else
            dfss2(u);
    }
}
int longest=0;
int best[1000000][2];
void dfs(int v,int p)
{
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (u==p)
            continue;
        dfs(u,v);
        if (best[u][0]+1>best[v][0])
        {
            best[v][1]=best[v][0];
            best[v][0]=best[u][0]+1;
        }
        else if (best[u][0]+1>best[v][1])
            best[v][1]=best[u][0]+1;
    }
    longest=max(longest,best[v][0]+best[v][1]);
}
int main()
{

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >>n>>m;
    for (int i=0;i<=n;i++)
    {
        adj[i].clear();
        adja[i].clear();
        vis[i]=viss[i]=viss2[i]=0;
        best[i][0]=best[i][1]=0;
        disc[i]=low[i]=comp[i]=0;
        bridge[i].clear();
        br[i]=0;
    }
    for (int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adja[a].push_back(b);
        adja[b].push_back(a);
        bridge[a].push_back(0);
        bridge[b].push_back(0);
    }
    num=0,longest=0;
    get_bridges(1);
    for (int i=1;i<=n;i++)
    {
        int k=adja[i].size();
        for (int j=0;j<k;j++)
        {
            if (adja[i][j]==pa[i])
                bridge[i][j]=br[i];
        }
    }
    int tot=1;
    for (int i=1; i<=n; i++)
    {
        if(comp[i]==0)
        {
            dfss(i,tot);
            tot++;
        }
    }
    for (int i=1; i<=n; i++)
    {
        if(viss2[i]==0)
        {
            dfss2(i);
            tot++;
        }
    }
    dfs(1,-1);
    cout<<longest<<endl;
}