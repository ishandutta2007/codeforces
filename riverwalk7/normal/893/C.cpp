#include <iostream>
#include <fstream>
#include <vector>
#define MAXN 100100
using namespace std;
typedef long long ll;
int N, M;
ll c[MAXN];
ll a[MAXN];
vector<int> conn[MAXN];
bool vis[MAXN];
int x, y;
ll ans;
ll dfs(int node)
{
    if(vis[node])
    {
        return a[node];
    }
    vis[node] = true;
    a[node] = c[node];
    for(int i=0; i<conn[node].size(); i++)
    {
        a[node] = min(a[node], dfs(conn[node][i]));
    }
    return a[node];
}
int main()
{
    cin>>N>>M;
    for(int i=1; i<=N; i++)
    {
        cin>>c[i];
    }
    for(int i=0; i<M; i++)
    {
        cin>>x>>y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    for(int i=1; i<=N; i++)
    {
        if(!vis[i])
        {
            ans += dfs(i);
        }
    }
    cout<<ans<<endl;
}