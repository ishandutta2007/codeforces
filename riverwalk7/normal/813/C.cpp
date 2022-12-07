#include <iostream>
#include <vector>
#define MAXN 200100
using namespace std;
vector<int> conn[MAXN];
int parent[MAXN][18];
int level[MAXN];
int x, y, d;
int N, Q;
void dfs(int node, int par, int lvl)
{
    parent[node][0] = par;
    level[node] = lvl;
    for(int i=0; i<conn[node].size(); i++)
    {
        if(conn[node][i]!=par)
        {
            dfs(conn[node][i], node, lvl+1);
        }
    }
}
int lca(int node1, int node2)
{
    if(level[node1] > level[node2])
    {
        swap(node1, node2);
    }
    for(int i=17; i>=0; i--)
    {
        if(level[parent[node2][i]] >= level[node1])
        {
            node2 = parent[node2][i];
        }
    }
    if(node1==node2)
    {
        return node1;
    }
    for(int i=17; i>=0; i--)
    {
        if(parent[node2][i]!=parent[node1][i])
        {
            node2 = parent[node2][i];
            node1 = parent[node1][i];
        }
    }
    return parent[node1][0];
}
int main()
{
    cin>>N>>Q;
    for(int i=0; i<N-1; i++)
    {
        cin>>x>>y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    dfs(1, 0, 1);
    for(int i=1; i<18; i++)
    {
        for(int j=1; j<=N; j++)
        {
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
    int s, t, ans;
    ans = 0;
    for(int i=2; i<=N; i++)
    {
        if(conn[i].size() == 1)
        {
            s = level[lca(i, Q)]; t = level[Q];
            if((t-s) < (s-1))
            {
                ans = max(ans, 2*(level[i]-1));
            }
        }
    }
    cout<<ans<<endl;
}