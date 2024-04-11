#include <bits/stdc++.h>
using namespace std;
long long a[1000001];
bool ok=1;
long long b[1000001];
long long k[1000001];
vector<int> adj[1000000];
long long need[1000000];
void dfs(int v)
{
    need[v]=b[v]-a[v];
    for (auto u:adj[v])
    {
        dfs(u);
        if (need[u]>0)
        {
            if (100000000000000000LL / need[u] < k[u])
                ok=0;
            need[v]+=need[u]*k[u];
            if (need[v]>100000000000000000LL)
                ok=0;
        }
        else
            need[v]+=need[u];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        cin>>b[i];
    for (int i=2;i<=n;i++)
    {
        int p;
        cin>>p>>k[i];
        adj[p].push_back(i);
    }
    dfs(1);
    if (need[1]<=0 && ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}