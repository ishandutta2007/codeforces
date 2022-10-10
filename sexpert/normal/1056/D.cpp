#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 3;
vector<int> adj[MAXN];
int leaves[MAXN];
int vist[MAXN];

int dfs(int src)
{
    int ans = 0;
    if(adj[src].empty())
        ans = 1;
    vist[src] = 1;
    for(auto v : adj[src])
    {
        if(!vist[v])
            ans += dfs(v);
    }
    leaves[src] = ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    vector<int> sizes;
    for(int i = 1; i <= n; i++)
        sizes.push_back(leaves[i]);
    sort(sizes.begin(), sizes.end());
    for(int i = 0; i < n; i++)
        cout << sizes[i] << " ";
    cout << endl;
}