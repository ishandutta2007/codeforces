#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN = 4e5 + 5;
int tin[MAXN], low[MAXN], comp[MAXN], sz[MAXN], vis[MAXN], cur, ccomp;
vector<int> adj[MAXN];
vector<ii> edges;
map<ii, ii> dir;

int dfs(int s, int p = 0) {
    low[s] = tin[s] = ++cur;
    //cout << "entered " << s << " at time " << tin[s] << '\n';
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        if(!low[v]) {
            dfs(v, s);
            if(low[v] > tin[s]) {
                //cout << s << " to " << v << " is bridge\n";
            }
            else {
                dir[{s, v}] = {s, v};
                dir[{v, s}] = {s, v};
                //cout << "orient " << s << " " << v << '\n';
            }
            low[s] = min(low[s], low[v]);
        }
        else if(tin[v] < tin[s]) {
            low[s] = min(low[s], tin[v]);
            dir[{s, v}] = {s, v};
            dir[{v, s}] = {s, v};
            //cout << "orient " << s << " " << v << '\n';
        }
    }
    return low[s];
}

void flood(int s, int c) {
    sz[c]++;
    comp[s] = c;
    for(auto v : adj[s]) {
        if(comp[v] || !dir.count({s, v})) continue;
        flood(v, c);
    }
}

void finish(int s) {
    vis[s] = 1;
    for(auto v : adj[s]) {
        if(vis[v]) continue;
        if(!dir.count({s, v})) {
            dir[{s, v}] = {v, s};
            dir[{v, s}] = {v, s};
        }
        finish(v);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    dfs(1);
    for(int i = 1; i <= n; i++)
        if(!comp[i]) flood(i, ++ccomp);
    int mx = 0, root;
    for(int i = 1; i <= n; i++) {
        int c = comp[i];
        if(sz[c] > mx) {
            mx = sz[c];
            root = i;
        }
    }
    finish(root);
    cout << mx << '\n';
    for(auto e : edges) {
        auto de = dir[e];
        cout << de.first << " " << de.second << '\n';
    }
}