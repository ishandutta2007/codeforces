# include <iostream>
# include <vector>
# include <cstring>
#include <ios>
#include <map>
#include <algorithm>
using namespace std;
int ans=0;
vector<int> adj[1000000];
vector<int> len[1000000];
int dist[1000000][2];
bool vis[1000000];
void calc(int v)
{
    vis[v]=1;
    int n=adj[v].size();
    int now=0;
    for (int i=0;i<n;i++)
    {
        int u=adj[v][i];
        if (!vis[u])
        {
            calc(u);
            dist[v][now++]=dist[u][1]+len[v][i];
        }
    }
    if (dist[v][0]>dist[v][1])
        swap(dist[v][0],dist[v][1]);
}
int main()
{
    int n;
    cin>>n;
    int m=(1<<(n+1))-2;
    int now=0;
    for (int i=0;i<m/2;i++)
    {
            now++;
        int x;
        int y;
        cin>>x>>y;
        adj[now].push_back(now*2);
        adj[now].push_back(now*2+1);
        adj[now*2].push_back(now);
        adj[now*2+1].push_back(now);
        len[now].push_back(x);
        len[now].push_back(y);
        len[now*2].push_back(x);
        len[now*2+1].push_back(y);
    }
    calc(1);
    for (int i=1;i<=m+1;i++)
    {
        ans+=dist[i][1]-dist[i][0];
    }
    cout<<ans<<endl;
}