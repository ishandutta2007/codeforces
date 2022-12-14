# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;
int ans = 1;
int group[1000000];
vector<int> groups[1000000];
vector<int> adj[1000000];
void add(int u, int v)
{
    int n = groups[group[u]].size();
    int h=group[u];
    int l=group[v];
    for (int i = 0; i < n; i++)
    {
        groups[l].push_back(groups[h][i]);
        group[groups[h][i]] = l;
    }
}
void dsu(int u,int v)
{
    if (group[u] == group[v])
        ans = (2*ans)%1000000009;
    else
    {
        if (groups[group[u]].size() < groups[group[v]].size())
            add(u, v);
        else
            add(v, u);
    }
}
int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        groups[i].push_back(i);
        group[i] = i;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        dsu(a, b);
        cout << (ans-1+1000000009)%1000000009<< endl;
    }
}