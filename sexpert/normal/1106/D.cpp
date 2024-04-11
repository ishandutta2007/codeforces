#include <bits/stdc++.h>
using namespace std;
 
set<int> acc, seen;
const int MAXN = 1e5 + 5;
vector<int> adj[MAXN], ans;
 
void dfs(int s) {
    acc.erase(s);
    seen.insert(s);
    ans.push_back(s);
    for(auto v : adj[s]) {
        if(!seen.count(v))
            acc.insert(v);
    }
    if(acc.empty())
        return;
    dfs(*acc.begin());
}
 
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    acc.insert(1);
    dfs(1);
    for(auto x : ans)
        cout << x << " ";
    cout << endl;
}