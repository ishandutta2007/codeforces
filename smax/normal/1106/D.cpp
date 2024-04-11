#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, m;
    bool visited[100000] = {false};
    set<int> adj[100000];
    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].insert(v-1);
        adj[v-1].insert(u-1);
    }
    
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(0);
    visited[0] = true;
    while (!pq.empty()) {
        int v = pq.top();
        pq.pop();
        cout << v+1 << " ";
        for (int u : adj[v])
            if (!visited[u]) {
                pq.push(u);
                visited[u] = true;
            }
    }
    
    return 0;
}