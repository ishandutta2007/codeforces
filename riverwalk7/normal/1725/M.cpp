#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
typedef long long ll;
struct QVertex
{
    int curV; ll dist;
    QVertex()
    {
        curV = dist = 0;
    }
    QVertex(int curV, ll dist)
    {
        this -> curV = curV;
        this -> dist = dist;
    }
    bool operator <(const QVertex &rhs) const
    {
        return dist > rhs.dist;
    }
};
int N, M;
int U, V; ll W;
vector<QVertex> conn[2*MAXN];
ll d[2*MAXN];
bool vis[2*MAXN];
void dijkstra(int source_node)
{
    priority_queue<QVertex> q;
    q.push(QVertex(source_node, 0));
    while(!q.empty())
    {
        QVertex cur = q.top();
        q.pop();
        if(!vis[cur.curV])
        {
            vis[cur.curV] = true;
            d[cur.curV] = cur.dist;
            for(auto neighbor: conn[cur.curV])
            {
                q.push(QVertex(neighbor.curV, cur.dist + neighbor.dist));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;
    for(int i=0; i<M; i++)
    {
        cin>>U>>V>>W;
        conn[U].push_back(QVertex(V, W));
        conn[V+N].push_back(QVertex(U+N, W));
    }
    for(int i=1; i<=N; i++)
    {
        conn[i].push_back(QVertex(i+N, 0));
    }
    dijkstra(1);
    for(int i=2; i<=N; i++)
    {
        if(!vis[i+N])
        {
            cout<<-1<<" ";
        }
        else
        {
            cout<<d[i+N]<<" ";
        }
    }
}