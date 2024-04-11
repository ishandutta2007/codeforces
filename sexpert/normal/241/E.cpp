#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;

const int MAXN = 1005;
const int INF = 1e9 + 10;
int qaq[MAXN], uwu[MAXN], owo[MAXN], n, m;

vector<vector<int>> adj, radj;
vector<ii> edges;

void dfs(int s, vector<vector<int>> &G) {
    uwu[s]++;
    qaq[s] = 1;
    for(auto v : G[s])
        if(!qaq[v])
            dfs(v, G);
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    radj.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    dfs(1, adj);
    memset(qaq, 0, sizeof qaq);
    dfs(n, radj);

    fill(owo, owo + MAXN, INF);
    owo[1] = 0;

    for(int rep = 0; rep < 2*n + 69; rep++) {
        for(int u = 1; u <= n; u++) {
            for(auto v : adj[u]) {
                if(uwu[u] < 2 || uwu[v] < 2)
                    continue;
                owo[v] = min(owo[v], owo[u] + 2);
                owo[u] = min(owo[u], owo[v] - 1);
            }
        }
    }
    vector<int> cute;
    for(auto e : edges) {
        int u = e.first, v = e.second;
        if(uwu[u] < 2 || uwu[v] < 2) {
            cute.push_back(1);
            continue;
        }
        int wt = owo[v] - owo[u];
        if(wt != 1 && wt != 2) {
            cout << "No\n";
            return 0;
        }
        cute.push_back(wt);
    }
    cout << "Yes\n";
    for(auto cutie : cute)
        cout << cutie << '\n';
}