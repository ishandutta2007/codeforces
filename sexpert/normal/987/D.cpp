#include <bits/stdc++.h>
using namespace std;

vector<int> vecinos[100005];
vector<int> types[105];
int minCosts[100005][105];
int n, m, k, s;

void bfs(int type)
{
    queue<int> q;
    vector<int> vist(n);
    for(int v : types[type])
    {
        //cout << types[type][0] << endl;
        vist[v] = 1;
        q.push(v);
        minCosts[v][type] = 0;
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v : vecinos[u])
        {
            if(!vist[v])
            {
                vist[v] = 1;
                q.push(v);
                minCosts[v][type] = minCosts[u][type] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k >> s;
    for(int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        types[v - 1].push_back(i);
    }
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        vecinos[x - 1].push_back(y - 1);
        vecinos[y - 1].push_back(x - 1);
    }
    for(int i = 0; i < k; i++)
    {
        bfs(i);
    }
    
    for(int i = 0; i < n; i++)
    {
        vector<int> costs(minCosts[i], minCosts[i] + k);
        sort(costs.begin(), costs.end());
        int ans = 0;
        for(int j = 0; j < s; j++)
        {
            ans += costs[j];
        }
        cout << ans << " ";
    }
}