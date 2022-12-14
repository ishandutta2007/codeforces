#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long a[1000000];
long long ret[1000000];
vector<int> adj[1000000];
int p[1000000];
bool ok=1;
void dfs(int v)
{
    if (a[v]!=-1)
    {
        ret[v]=a[v]-a[p[v]];
        for (auto u:adj[v])
        {
            dfs(u);
        }
    }
    else
    {
        long long mn = 1e9+3;
        for (auto u:adj[v])
        {
            if (a[u]!=-1)mn=min(mn,a[u]);
        }
        if (mn==1e9+3) {
            ret[v]=0;
            a[v]=a[p[v]];
        } else {
            if (a[p[v]]>mn)ok=0;
            else a[v]=mn,ret[v]=a[v]-a[p[v]];
        }
        for (auto u:adj[v])
        {
            dfs(u);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for (int i=2;i<=n;i++)
    {
        cin>>p[i];
        adj[p[i]].push_back(i);
    }
    for (int i=1;i<=n;i++)
        cin>>a[i];
    dfs(1);
    if (!ok)cout<<-1<<endl;
    else{
        long long sum=0;
        for (int i=1;i<=n;i++)
            sum+=ret[i];
        cout<<sum<<endl;
    }
}