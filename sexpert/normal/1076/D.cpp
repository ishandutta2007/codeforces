#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> pll;

const int MAXN = 3e5 + 2;
const long long INF = 1e15;
const int src = 1;
vector<pll> adj[MAXN];
vector<long long> dist(MAXN, INF);
vector<long long> parent(MAXN);
vector<bool> vist(MAXN, false);
map<pll, int> mp;
int n, m, k, used = -1;

void dijkstra()
{
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        if(vist[u])
            continue;
        //cout << "visiting " << u << endl;
        used++;
        vist[u] = true;
        if(used == k)
            break;
        for(auto p : adj[u])
        {
            long long v = p.first, w = p.second;
            //cout << "checking " << v << endl;
            if(dist[v] > dist[u] + w)
            {
                //cout << "distance to " << v << " updated to " << dist[u] + w << " through " << u << endl;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
                parent[v] = u;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        mp[{min(u, v), max(u, v)}] = i + 1;
    }
    dijkstra();
    vector<int> ans;
    for(int v = 2; v <= n; v++)
    {
        if(vist[v])
        {
            int u = parent[v];
            ans.push_back(mp[{min(u, v), max(u, v)}]);
        }
    }
    cout << ans.size() << endl;
    for(auto e : ans)
        cout << e << " ";
    cout << endl;
}