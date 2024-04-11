#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
int rep[MAXN];
vector<int> adj[MAXN], tour;

int find(int u) {
    return rep[u] == 0 ? u : rep[u] = find(rep[u]);
}

bool join(int u, int v) {
    u = find(u), v = find(v);
    if(u == v)
        return false;
    rep[v] = u;
    return true;
}

void dfs(int s, int p = 0) {
    tour.push_back(s);
    for(auto v : adj[s]) {
        if(v == p)
            continue;
        dfs(v, s);
        tour.push_back(s);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if(!join(u, v))
            continue;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    int sz = (2*n + k - 1)/k;
    for(int i = 0; i < k; i++) {
        int cur = 0;
        if(tour.size()) {
            int tot = 0, mx = tour.size(), amt = min(mx, sz);
            cout << amt << " ";
            while(tot < amt) {
                cout << tour.back() << " ";
                tour.pop_back();
                tot++;
            }
            cout << '\n';
        }
        else
            cout << "1 1\n";

    }
}