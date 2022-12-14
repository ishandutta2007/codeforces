#include <bits/stdc++.h>
using namespace std;
bool vis[1000000];
long long ret=0;
int n;
void dfs(int v)
{
    vis[v]=1;
    for (int i=v+v;i<=n;i+=v)
    {
        if (!vis[i])dfs(i);
        ret+=2*(i/v);
    }
    for (int i=2;i*i<=v;i++)
    {
        if (v%i)continue;
        if (!vis[i])dfs(i);
        ret+=2*(v/i);
        if (i!=v/i)
        {
            if (!vis[v/i])dfs(v/i);
            ret+=2*(i);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    cin>>n;
    long long ans=0;
    for (int i=2;i<=n;i++)
        if (!vis[i])
            dfs(i),ans=max(ans,ret),ret=0;
    cout<<ans<<endl;
}