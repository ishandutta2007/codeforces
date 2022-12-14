#include <bits/stdc++.h>
using namespace std;
int c[1000000];
vector<int> cur;
int num[1000000];
int mx=0;
bool vis[1000000];
vector<int> adj[1000000];
void dfs(int v)
{
    vis[v]=1;
    cur.push_back(c[v]);
    num[c[v]]++;
    if (num[c[v]]>mx)mx=num[c[v]];
    for (int i=0;i<adj[v].size();i++)
    {
        int u=adj[v][i];
        if (vis[u])continue;
        dfs(u);
    }
}
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for (int i=1;i<=n;i++)
        cin>>c[i];
    for (int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;
        adj[l].push_back(r);
        adj[r].push_back(l);
    }
    int ret=0;
    for (int i=1;i<=n;i++)
    {
        if (!vis[i])
        {
            mx=0;
            cur.clear();
            dfs(i);
            ret += cur.size()-mx;
            for (int j=0;j<cur.size();j++)
                num[cur[j]]=0;
        }
    }
    cout<<ret<<endl;
}