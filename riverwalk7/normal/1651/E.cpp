#include <bits/stdc++.h>
#define MAXN 1510
using namespace std;
typedef long long ll;
int N;
int adj[2*MAXN][2];
int conn[2*MAXN][2];
bool vis[2*MAXN];
int dfs_start;
ll x, y;
ll ans;
void dfs(int node)
{
    vis[node] = true;
    for(int i=0; i<2; i++)
    {
        if(!vis[adj[node][i]])
        {
            conn[node][0] = adj[node][i];
            conn[adj[node][i]][1] = node;
            dfs(adj[node][i]);
        }
    }
    if(conn[node][0] == 0)
    {
        conn[node][0] = dfs_start;
        conn[dfs_start][1] = node;
    }
}
void add_edge(int xx, int yy)
{
    if(adj[xx][0] == 0)
    {
        adj[xx][0] = yy;
    }
    else
    {
        adj[xx][1] = yy;
    }

    if(adj[yy][0] == 0)
    {
        adj[yy][0] = xx;
    }
    else
    {
        adj[yy][1] = xx;
    }
}
ll query(int minx, int maxx, int miny, int maxy, int o1, int o2)
{
    if(o1 > o2) // o1 > N and o2 <= N in this case, we want to swap them
    {
        swap(o1, o2);
    }
    ll possiblex, possibley;

    //compute the number of possible x ranges
    if(o1 < minx)
    {
        possiblex = (minx-o1)*(N-maxx+1);
    }
    else if(o1 > maxx)
    {
        possiblex = minx*(o1-maxx);
    }
    else
    {
        possiblex = 0;
    }
    //compute the number of possible y ranges
    if(o2 < miny)
    {
        possibley = (miny-o2)*(2*N-maxy+1);
    }
    else if(o2 > maxy)
    {
        possibley = (miny-N)*(o2-maxy);
    }
    else
    {
        possibley = 0;
    }
    return possiblex * possibley;
}
void process(int node)
{
    int minx, maxx, miny, maxy;
    if(node <= N)
    {
        minx = maxx = node;
        miny = 2*MAXN; maxy = 0;
    }
    if(node > N)
    {
        minx = 2*MAXN; maxx = 0;
        miny = maxy = node;
    }
    int cur = node;
    do
    {
        if((node-1)/N != (cur-1)/N)
        {
            ans += query(minx, maxx, miny, maxy, conn[node][1], conn[cur][0]);
        }
        cur = conn[cur][0];
        if(cur > N)
        {
            miny = min(miny, cur);
            maxy = max(maxy, cur);
        }
        if(cur <= N)
        {
            minx = min(minx, cur);
            maxx = max(maxx, cur);
        }
    } while(cur != node);
}
int main()
{
    cin>>N;
    for(int i=0; i<2*N; i++)
    {
        cin>>x>>y;
        add_edge(x, y);
        ans += (x*(N-x+1)*(y-N)*(2*N-y+1));
    }
    for(int i=1; i <= 2*N; i++)
    {
        if(!vis[i])
        {
            dfs_start = i;
            dfs(i);
        }
    }
    for(int i=1; i<=2*N; i++)
    {
        process(i);
    }
    ans /= 2;
    cout<<ans<<endl;
}