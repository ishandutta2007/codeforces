#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, parent[1000], childCount[1000] = {0};
    bool children[1000] = {false}, visited[1000] = {false};
    vector<int> adj[1000];
    cin >> n;
    for (int i=1; i<=n-1; i++) {
        int p;
        cin >> p;
        adj[p-1].push_back(i);
        parent[i] = p - 1;
    }
    
    parent[0] = -1;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        bool isChild = true;
        for (int u : adj[v])
            if (!visited[u]) {
                isChild = false;
                q.push(u);
                visited[u] = true;
            }
        if (isChild && parent[v] != -1) {
            children[v] = true;
            childCount[parent[v]]++;
        }
    }
    
    for (int i=0; i<n; i++)
        if (!children[i] && childCount[i] < 3) {
            cout << "No" << endl;
            return 0;
        }
    
    cout << "Yes" << endl;
    
    return 0;
}