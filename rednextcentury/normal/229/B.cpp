#include<stdio.h>
# include <map>
#include<algorithm>
# include <iostream>
# include <queue>
# include <vector>
using namespace std;
#define INF (1LL<<50)
long long dist[1000000];
vector<int> adj[1000000];
vector<int> len[1000000];
int it[1000000];
vector<int> r[1000000];
int n;
bool vis[1000000];
map<int,int> wait[1000000];
void dijkstra()
{
    for (int i=1;i<=n;i++)
        dist[i]=INF,vis[i]=0;
    dist[1]=wait[1][0];
    priority_queue<pair<long long,int> > q;
    q.push(make_pair(-dist[1],1));
    while(!q.empty())
    {
        int v=q.top().second;
        long long cur=-q.top().first;
        q.pop();
        if (vis[v])continue;
        vis[v]=1;
        int m=adj[v].size();
        for (int i=0;i<m;i++)
        {
            int u=adj[v][i];
            long long now=cur+len[v][i]+wait[u][cur+len[v][i]];
            if (u==n)
                now-=wait[u][cur+len[v][i]];

            if (now<dist[u])
            {
                dist[u]=now;

                q.push(make_pair(-dist[u],u));
            }
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=0;i<m;i++)
    {
        int s,e,c;
        cin>>s>>e>>c;
        adj[e].push_back(s);
        adj[s].push_back(e);
        len[s].push_back(c);
        len[e].push_back(c);
    }
    for (int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        it[i]=0;
        while(k--)
        {
            int t;
            cin>>t;
            r[i].push_back(t);
        }
        if (r[i].size()==0)
            continue;
        wait[i][r[i][r[i].size()-1]]=1;
        for (int j=(int)r[i].size()-2;j>=0;j--)
        {
            if (r[i][j+1]==r[i][j]+1)
                wait[i][r[i][j]]=wait[i][r[i][j+1]]+1;
            else
                wait[i][r[i][j]]=1;
        }
    }
    dijkstra();
    if (dist[n]==INF)
        cout<<-1<<endl;
    else
        cout<<dist[n]<<endl;
}