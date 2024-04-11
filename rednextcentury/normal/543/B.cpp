# include <iostream>
# include <vector>
# include <stdio.h>
#include <limits.h>
#include <stack>
#include <queue>
using namespace std;
bool vis[4000][4000];
int dist[4000][4000];
vector<int> adj[1000000];
void bfs(int s,int t)
{
    queue<int> q;
    q.push(s);
    vis[s][t]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        int n=adj[v].size();
        for (int i=0;i<n;i++)
        {
            int u=adj[v][i];
            if (vis[u][t])
                continue;
            q.push(u);
            vis[u][t]=1;
            dist[u][t]=dist[v][t]+1;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int s1,t1,l1;
    int s2,t2,l2;
    cin>>s1>>t1>>l1;
    cin>>s2>>t2>>l2;
    for (int i=1;i<=n;i++)
    {
        bfs(i,i);
    }
    int mn=1000000;
    if (dist[s1][t1]<=l1 && dist[s2][t2]<=l2)
    {
        mn=dist[s1][t1]+dist[s2][t2];
    }
    else
    {


        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (dist[i][s1]+dist[j][i]+dist[t1][j]>l1 || dist[i][s2]+dist[j][i]+dist[t2][j]>l2)
                continue;

            mn=min(mn,dist[i][s1]+dist[i][s2]+dist[i][j]+dist[t1][j]+dist[t2][j]);
        }
    }
    swap(s2,t2);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (dist[i][s1]+dist[j][i]+dist[t1][j]>l1 || dist[i][s2]+dist[j][i]+dist[t2][j]>l2)
                continue;

            mn=min(mn,dist[i][s1]+dist[i][s2]+dist[i][j]+dist[t1][j]+dist[t2][j]);
        }
    }
    if (mn>m)
        cout<<-1<<endl;
    else
    cout<<m-mn<<endl;
}