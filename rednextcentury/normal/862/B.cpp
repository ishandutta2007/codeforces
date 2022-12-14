#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int col[1000001];
bool vis[1000001];
long long num[4];
vector<int> adj[1000001];
void dfs(int v,int c)
{
    col[v]=c;
    num[c]++;
    vis[v]=1;
    for (auto u:adj[v])
    {
        if (vis[u])continue;
        dfs(u,1-c);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);
    long long ret = num[0]*num[1]-n+1;
    cout<<ret<<endl;

}