#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> groups[1000000];
map<int,int> mp[1000000];
int group[1000000];
void Merge(int u,int v)
{
    for (int i=0;i<groups[u].size();i++)
    {
        groups[v].push_back(groups[u][i]);
        group[groups[u][i]]=v;
    }
    groups[u].clear();
}
void dsu(int x,int y)
{
    int u = group[x];
    int v = group[y];
    if (u==v)return;
    if (groups[u].size()<groups[v].size())
        Merge(u,v);
    else
        Merge(v,u);
}
vector<pair<int,pair<int,int> > > edges[1000001];
int ret[1000000];
string ans[] = {"none","any","at least one"};

int o=1;
int disc[1000000];
int low[1000000];
bool vis[1000000];
vector<pair<int,int> > adj[1000000];
int pa[1000000];

void get_bridges(int v)
{
    disc[v]=low[v]=o;
    o++;
    vis[v]=1;
    int n=adj[v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i].first;
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
            ret[adj[v][i].second] = 1;
    }
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        group[i]=i,groups[i].push_back(i);
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges[w].push_back(make_pair(i,make_pair(u,v)));
    }
    for (int i=1;i<=1000000;i++)
    {
        for (int j=0;j<edges[i].size();j++)
        {
            int u = group[edges[i][j].second.first];
            int v = group[edges[i][j].second.second];
            if (u==v)
                ret[edges[i][j].first]=0;
            else
            {
                mp[u][v]++;
                mp[v][u]++;
                adj[u].push_back(make_pair(v,edges[i][j].first));
                adj[v].push_back(make_pair(u,edges[i][j].first));
            }
        }
        o = 1;
        for (int j=0;j<edges[i].size();j++)
        {
            int u = group[edges[i][j].second.first];
            int v = group[edges[i][j].second.second];
            if (u==v)continue;
            if (!vis[u])
                get_bridges(u);
        }
        for (int j=0;j<edges[i].size();j++)
        {
            int u = group[edges[i][j].second.first];
            int v = group[edges[i][j].second.second];
            if (u==v)continue;
            if (ret[edges[i][j].first]!=1)
                ret[edges[i][j].first] = 2;
            if (ret[edges[i][j].first]==1)
                if (mp[u][v]>1)
                    ret[edges[i][j].first]=2;
            vis[u]=0,vis[v]=0;
            pa[u]=0,pa[v]=0;
            adj[u].clear(),adj[v].clear();
        }

        for (int j=0;j<edges[i].size();j++)
            dsu(edges[i][j].second.first,edges[i][j].second.second);
    }

    for (int i=1;i<=m;i++)
        cout<<ans[ret[i]]<<endl;
}