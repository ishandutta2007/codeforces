#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;
long long w[1000000];
int lev[1000000];
int pa[100100][20];
long long dist[1000000];
long long L,S;
vector<int> adj[1000000];
void dfs(int v)
{
    for (auto u:adj[v])
    {
        lev[u]=lev[v]+1;
        dist[u]=dist[v]+w[u];
        dfs(u);
    }
}
long long bS[1000001];
long long bL[1000001];
bool ok=1;
int ret=0;
int getSol(int v,long long l,long long s)
{
    int x=v;
    for (int i=19;i>=0;i--)
    {
        int u=pa[v][i];
        if (S-s >= dist[x]-w[x]-dist[u]+w[u])
            v=u;
    }
    return max(lev[v]+0LL,lev[x]-(L-l));
}
void sol(int v)
{
    int best=lev[v]+1;
    bL[v]=0;
    bS[v]=0;
    if (w[v]>S)
        ok=0;
    for (auto u:adj[v])
    {
        sol(u);
        int cur = getSol(u,bL[u],bS[u]);
        if (cur<best)
            best=cur,bS[v]=bS[u],bL[v]=bL[u];
    }
    if (best==lev[v]+1)ret++;
    bS[v]+=w[v];
    bL[v]++;
    if (ok)
        assert(bS[v]<=S && bL[v]<=L);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n>>L>>S;
    for (int i=1;i<=n;i++)
        cin>>w[i];
    for (int i=2;i<=n;i++)
    {
        cin>>pa[i][0];
        adj[pa[i][0]].push_back(i);
    }
    dist[1]=w[1];
    dfs(1);
    for (int i=1;i<20;i++)
        for (int j=1;j<=n;j++)
            pa[j][i]=pa[pa[j][i-1]][i-1];
    sol(1);
    if (!ok)ret=-1;
    cout<<ret<<endl;
}