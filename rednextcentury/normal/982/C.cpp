#include <bits/stdc++.h>
using namespace std;
int sol[1000000];
int ret=0;
vector<int> adj[1000000];
void dfs(int v,int p)
{
    int sum=0;
    for (int i=0;i<adj[v].size();i++)
    {
        int u = adj[v][i];
        if (u==p)continue;
        dfs(u,v);
        sum+=sol[u];
    }
    if (sum%2)
        sol[v]=0;
    else
        sol[v]=1;
    ret+=1-sol[v];
}
int main()
{
    int n;
    cin>>n;
    if (n%2)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    cout<<ret-1<<endl;
}