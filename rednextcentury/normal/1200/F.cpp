#include <bits/stdc++.h>
using namespace std;
bool vis[1001][2521];
bool in_stack[1001][2521];
int mod = 2520;
int st2[2001];
int cur=0;
int AA=0;
int m[10000];
int k[1000000];
int ans[1001][2521];
int adj[1001][20];
vector<pair<int,int> > vec;
pair<int,int> par[1001][2521];

void dfs(int v,long long c)
{
    vec.push_back({v,c});
    vis[v][c]=1;
    in_stack[v][c]=1;
    int u = adj[v][c%m[v]];
    long long cc = c+k[u];
    cc=(cc%mod+mod)%mod;
    if (vis[u][cc] && in_stack[u][cc])
    {
        cur=0;
        pair<int,int> p = {v,c};
        pair<int,int> g = {u,cc};
        while(p!=g)
        {
            st2[p.first]++;
            if (st2[p.first]==1)cur++;
            p = par[p.first][p.second];
        }

        st2[p.first]++;
        if (st2[p.first]==1)cur++;

        AA=cur;
    }
    else if (vis[u][cc])
        AA=ans[u][cc];
    else{
        par[u][cc]={v,c};
        dfs(u,cc);
    }
    in_stack[v][c]=0;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>k[i];
    for (int i=1;i<=n;i++)
    {
        cin>>m[i];
        for (int j=0;j<m[i];j++)
            cin>>adj[i][j];
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<mod;j++)
        {
            if (vis[i][j])continue;
            dfs(i,j);
            for (auto p:vec)ans[p.first][p.second]=AA,st2[p.first]=0;
            vec.clear();
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int v,kk;
        cin>>v>>kk;
        kk+=k[v];
        kk=(kk%mod+mod)%mod;
        cout<<ans[v][kk]<<endl;
    }
}