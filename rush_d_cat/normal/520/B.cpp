#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
const int NICO = 10002;
typedef long long ll;
int m, n;
int vis[NICO], dis[NICO];
int res = NICO;
void bfs(int x, int y)
{
    for(int i=1;i<NICO;i++) dis[i] = NICO;
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    dis[x] = 0;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur-1>=1 && !vis[cur-1])
        {
            vis[cur-1] = 1;
            q.push(cur-1);
            dis[cur-1] = dis[cur] + 1;
        }
        if(cur*2<=10000&&!vis[2*cur])
        {
            vis[2*cur] = 1;
            q.push(2*cur);
            dis[2*cur] = dis[cur] + 1;
        }
    }
    res = dis[y];
}
int main()
{
    cin >> n >> m;
    bfs(n,m);
    cout << res << endl;
}