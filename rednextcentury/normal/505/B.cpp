#include <iostream>
# include <cstdlib>
# include <algorithm>
#include<cstdio>
# include <vector>
#include <cmath>
#include <map>
#include<set>
#include <stack>
using namespace std;
vector<int> adj[101][101];
int groups[101][101];
bool vis[101][101];
void dfs(int col,int v,int group)
{
    vis[col][v]=1;
    groups[col][v]=group;
    int n=adj[col][v].size();
    for (int i=0;i<n;i++)
    {
        int u=adj[col][v][i];
        if (vis[col][u])
            continue;
        else
            dfs(col,u,group);
    }
}
int g[101];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        adj[c][a-1].push_back(b-1);
        adj[c][b-1].push_back(a-1);
    }
    for (int i=1;i<=m;i++)
    {
        g[i]=1;
        for (int x=0;x<n;x++)
        {
            if (!vis[i][x])
            {
                dfs(i,x,g[i]);
                g[i]++;
            }
        }
    }
    int q;
    cin>>q;
    for (int i=0;i<q;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        int ans=0;
        for (int j=1;j<=m;j++)
        {
            if (groups[j][x]==groups[j][y] && groups[j][x]>0)
                ans++;
        }
        cout<<ans<<endl;
    }
}