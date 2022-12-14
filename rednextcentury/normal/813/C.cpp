#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define F first
#define pb push_back
#define S second
#define pi pair<int,int>
#define pii pair<pi,int>
#define go ios::sync_with_stdio(0)
vector<int> adj[200100];
int distr[200100],dista[200100];
void BFS(int s,int dist[])
{
    dist[s]=0;
    queue<int> q;
    q.push(s);
    dist[0]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(int i=0;i<adj[p].size();i++)
        {
            int u=adj[p][i];
            if(dist[u]==-1)
            {
                dist[u]=dist[p]+1;
                q.push(u);
            }
        }
    }
    return;
}
int main()
{
    go;
    int ans=0;
    int n,a;
    cin>>n>>a;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    memset(dista,-1,sizeof dista);
    memset(distr,-1,sizeof distr);
    BFS(1,distr);
    BFS(a,dista);
    for(int i=1;i<=n;i++)
    {
        if(dista[i]<distr[i])
            ans=max(ans,2*distr[i]);
    }
    cout<<ans;
    return 0;
}