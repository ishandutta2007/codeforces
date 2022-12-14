#include <bits/stdc++.h>
using namespace std;
vector<long long> a;
vector<int> adj[1000];
vector<pair<int,int> > E;
int dist[1000];
int vis[1000];
pair<int,int> forbidden;
int n;
int bfs(int s,int e)
{
    for (int i=0;i<n;i++)dist[i]=1e6,vis[i]=0;
    dist[s]=0;
    vis[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int v = q.front();q.pop();
        for (auto u:adj[v])
        {
            if (u==forbidden.first && v==forbidden.second)continue;
            if (v==forbidden.first && u==forbidden.second)continue;
            if (vis[u])continue;
            vis[u]=1;
            dist[u]=dist[v]+1;
            q.push(u);
        }
    }
    return dist[e]+1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        long long x;
        cin>>x;
        if (x!=0)a.push_back(x);
    }
    n=a.size();
    if (n>150)cout<<3<<endl;
    else{
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
            {
                if (i!=j && a[i]&a[j])
                    E.push_back({i,j}),adj[i].push_back(j),adj[j].push_back(i);
            }
        }
        int mn=1e6;
        for (auto e:E)
        {
            forbidden = e;
            mn = min(mn,bfs(e.first,e.second));
        }
        if (mn>=1e6)mn=-1;
        cout<<mn<<endl;
    }
}