#include <bits/stdc++.h>
using namespace std;
int t[1000000];
vector<int> adj[1000000];
int num[1000000];
void pre(int v)
{
    for (auto u:adj[v])
        pre(u),num[v]+=num[u];
    if (adj[v].size()==0)num[v]=1;
}
int dfs(int v)
{
    int mx=0,mn=1000000;
    long long sum=0;
    long long sum2=0;
    if (adj[v].size()==0)return 0;
    for (auto u:adj[v])
    {
        int x = dfs(u);
        mn=min(mn,x);
        mx=max(mx,x);
        sum+=x;
    }
    if (t[v]==0)
        return (sum+adj[v].size()-1);
    else
        return (mn);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>t[i];
    for (int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    pre(1);
    cout<<num[1]-dfs(1)<<endl;
}