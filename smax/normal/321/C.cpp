#include <bits/stdc++.h>
using namespace std;

struct CentroidDecomposition {
    vector<int> sub, parent;
    vector<bool> visited;
    vector<vector<int>> adj;

    CentroidDecomposition(vector<vector<int>> &_adj) {
        adj = _adj;
        int n = adj.size();
        sub.resize(n);
        parent.resize(n);
        visited.assign(n, false);
        build(0, -1);
    }

    void build(int u, int p) {
        int n = dfs(u, p);  // get size of subtree
        int c = centroid(u, p, n);  // find centroid of subtree
        parent[c] = p;
        visited[c] = true;

        // do the same for each of the subtrees rooted by the children of the current centroid
        for (int v : adj[c])
            if (!visited[v])
                build(v, c);
    }

    int dfs(int u, int p) {
        sub[u] = 1;
        for (int v : adj[u])
            if (v != p && !visited[v])
                sub[u] += dfs(v, u);
        return sub[u];
    }

    int centroid(int u, int p, int n) {
        for (int v : adj[u])
            if (v != p && !visited[v] && sub[v] > n / 2)
                return centroid(v, u, n);
        return u;
    }

    int operator [] (int i) {
        return parent[i];
    }
};

char ret[100000];
bool visited[100000] = {};
vector<vector<int>> adj;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i=0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    CentroidDecomposition cd(adj);

    for (int i=0; i<n; i++)
        if (!visited[i]) {
            stack<int> s;
            s.push(i);
            while (cd[s.top()] != -1 && !visited[cd[s.top()]])
                s.push(cd[s.top()]);

            char Rank = (cd[s.top()] == -1 ? 'A' : ret[cd[s.top()]] + 1);
            while (!s.empty()) {
                if (Rank > 'Z') {
                    cout << "Impossible!\n";
                    return 0;
                }
                ret[s.top()] = Rank++;
                visited[s.top()] = true;
                s.pop();
            }
        }

    for (int i=0; i<n; i++)
        cout << ret[i] << " ";
    cout << "\n";

    return 0;
}