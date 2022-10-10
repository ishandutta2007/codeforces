#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000
#define LOG2N 17

int n, parent[MAXN], depth[MAXN];
int ancestor[MAXN][LOG2N];  // ancestor[i][j] stores the 2^jth ancestor of node i
vector<int> adj[MAXN];

void dfs(int u, int d) {
    depth[u] = d;
    for (int v : adj[u])
        if (v != parent[u]) {
            parent[v] = u;
            dfs(v, d + 1);
        }
}

// O(n log n) preprocessing
void preprocess() {
    memset(ancestor, -1, sizeof(ancestor));
    for (int i=0; i<n; i++)
        ancestor[i][0] = parent[i];
    for (int j=1; (1<<j)<=n; j++)
        for (int i=0; i<n; i++)
            if (ancestor[i][j-1] != -1)
                ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
}

// O(log n) query
int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);

    // find ancestor of node u at the same level at v
    int w = u;
    for (int j=LOG2N-1; j>=0; j--)
        if (depth[w] - (1<<j) >= depth[v])
            w = ancestor[w][j];

    // from that same level, find ancestor of both by moving same number of steps upward
    if (v == w)
        return v;
    for (int j=LOG2N-1; j>=0; j--)
        if (ancestor[v][j] != -1 && ancestor[v][j] != ancestor[w][j]) {
            v = ancestor[v][j];
            w = ancestor[w][j];
        }
    return parent[v];
}

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    parent[0] = -1;
    dfs(0, 0);
    preprocess();

    int q;
    cin >> q;
    while (q--) {
        int x, y, a, b, k;
        cin >> x >> y >> a >> b >> k;
        x--, y--, a--, b--;

        int d = dist(a, b);
        if (d <= k && d % 2 == k % 2)
            cout << "YES\n";
        else {
            d = dist(a, x) + dist(y, b) + 1;
            if (d <= k && d % 2 == k % 2)
                cout << "YES\n";
            else {
                d = dist(a, y) + dist(x, b) + 1;
                if (d <= k && d % 2 == k % 2)
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }

    return 0;
}