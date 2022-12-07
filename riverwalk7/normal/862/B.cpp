#include <iostream>
#include <fstream>
#include <vector>
typedef long long ll;
#define MAXN 100100
using namespace std;
ll N;
vector<int> conn[MAXN];
bool vis[MAXN];
int x, y;
ll c1, c2;
void dfs(int node, bool g)
{
    if(vis[node])
    {
        return;
    }
    vis[node] = true;
    if(g)
    {
        c2++;
    }
    else
    {
        c1++;
    }
    for(int i=0; i<conn[node].size(); i++)
    {
        dfs(conn[node][i], !g);
    }
}
int main()
{
    cin>>N;
    for(int i=0; i<N-1; i++)
    {
        cin>>x>>y;
        conn[x].push_back(y);
        conn[y].push_back(x);
    }
    dfs(1, false);
    cout<<(c1*c2-(N-1))<<endl;
}