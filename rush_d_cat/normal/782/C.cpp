#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;
const int NICO = 1000000 + 10;
vector<int> vec[NICO];
int n, u, v, cnt;
int a[NICO], vis[NICO];
void dfs(int cur, int par)
{
    int col = 1;
    for(int i=0;i<vec[cur].size();i++)
    {
        int x = vec[cur][i];
        if(x == par) continue;
        while(a[par] == col || a[cur] == col) col ++;
        a[x] = col ++; 
        dfs(x, cur);
    }
}
int main()
{
    cin >> n;
    for(int i=1;i<n;i++)
    {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    a[1] = 1;
    dfs(1, 0);
    for(int i=1;i<=n;i++)
    {
        if(vis[a[i]] == 0) cnt ++, vis[a[i]] = 1;
    }
    cout << cnt << endl;
    for(int i=1;i<=n;i++)
    {
        cout << a[i] << " ";
    }
}