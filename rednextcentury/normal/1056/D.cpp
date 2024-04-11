#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int num[1000000];
int sz[1000000];
vector<int> adj[1000000];
void dfs(int v=1)
{
    sz[v]=0;
    for (auto u:adj[v])
        dfs(u),sz[v]+=sz[u];
    if (adj[v].size()==0)sz[v]++;
    num[sz[v]]++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        int p;
        cin>>p;
        adj[p].push_back(i);
    }
    dfs();
    int cur=1;
    int tot=0;
    for (int i=1;i<=n;i++)
    {
        while(tot<i)tot+=num[cur],cur++;
        cout<<cur-1<<' ';
    }
}