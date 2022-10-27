#include <vector>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int NICO = 200002;
const int INF = 1000000002;
int par[NICO], c[NICO];
vector<int> vec[NICO], edge[NICO];
int used[NICO], dis[NICO];
int n;

int find(int x)
{
    if(par[x] == -1) return x;
    return par[x] = find(par[x]);
}

void unite(int x, int y)
{
    int x_ = find(x);
    int y_ = find(y);
    if(x_ != y_)
    {
        par[x_] = y_;
    }
}

void bfs(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i] = INF;
        used[i] = 0;
    }
    s = find(s);
    queue<int> q;
    used[s] = 1;
    dis[s] = 0;
    q.push(s);
    while(!q.empty())
    {
        int cur = q.front();
        //cout << cur << endl;
        q.pop();
        for(int i=0;i<edge[cur].size();i++)
        {
            if(!used[edge[cur][i]])
            {
                used[edge[cur][i]] = 1;
                q.push(edge[cur][i]);
                dis[edge[cur][i]] = dis[cur] + 1;
            }
        }
    }
}


int main()
{
    cin >> n;
    for(int i=1;i<=n;i++) cin>>c[i], par[i]=-1;
    for(int i=1;i<=n-1;i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
        if(c[u] == c[v]) unite(u, v);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            int x = find(i), y = find(vec[i][j]);
            if(x != y)
            {
                edge[x].push_back(y);
                edge[y].push_back(x);
            }
        }
    }
    bfs(1);
    int p = -1, max_ = -1;
    for(int i=1;i<=n;i++)
    {
        if(dis[i] > max_ && dis[i] != INF) max_ = dis[p=i];
    }
    //cout << "============"<<endl;
    bfs(p);
    max_ = -1;
    for(int i=1;i<=n;i++)
    {
        if(dis[i] > max_ && dis[i] != INF) max_ = dis[i];
    }
    int res = (max_+1)/2;
    cout << res << endl;
}