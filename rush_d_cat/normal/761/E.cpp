#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int NICO = 10000 + 10;
typedef long long ll;
vector<int> vec[32];
int n, u, v;
int used[32];
int rk[32], deg[32];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int vis[32][6];
ll x_[32], y_[32];
void dfs(int x)
{
    used[x] = 1;
    for(int i=0;i<vec[x].size();i++)
    {
        int cur = vec[x][i];
        if(used[cur]) continue;
        rk[cur] = rk[x] + 1;
        deg[cur]++, deg[x]++;
        dfs(cur);
    }
}
void dfs1(int x, int dir)
{
    used[x] = 1;
    vis[x][dir] = 1;
    int d = 0;
    for(int i=0;i<vec[x].size();i++)
    {
        int cur = vec[x][i];
        if(used[cur]) continue;
        if(vis[x][d]) d++;
        x_[cur] = x_[x] + (1<<(30-rk[x]))*dx[d];
        y_[cur] = y_[x] + (1<<(30-rk[x]))*dy[d];
        dfs1(cur, 3-d);
        d++;
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<=n-1;i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    rk[1] = 1;x_[1]=0, y_[1] = 0;
    dfs(1);bool ok = 1;
    for(int i=1;i<=n;i++)
    {
        used[i] = 0;
        if(deg[i] > 4) ok = 0;
    }
    if(ok == 0)
    {
        cout << "NO" << endl;
        return 0;
    } 
    cout << "YES" << endl;
    dfs1(1, 5);
    for(int i=1;i<=n;i++)
    {
        cout << x_[i] << " " << y_[i] << endl;
    }
}