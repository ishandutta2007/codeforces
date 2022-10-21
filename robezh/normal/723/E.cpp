#include <bits/stdc++.h>
using namespace std;

const int N = 205;
typedef pair<int, int> P;

int n, m;
set<int> G[N];
set<P> odd_edges;
vector<P> res;
int even[N];

void add_edge(int u, int v) {
    res.push_back({u, v});
}

void dfs(int v){
    if(even[v]) {
        while(G[v].size()) {
            int nxt = *G[v].begin();
            G[v].erase(nxt);
            G[nxt].erase(v);
            add_edge(v, nxt);
            if(!even[nxt]) odd_edges.erase({nxt, v});
            dfs(nxt);
        }
    }
    else {
        auto p = *odd_edges.begin();
        G[p.first].erase(p.second);
        G[p.second].erase(p.first);
        odd_edges.erase(p);
        odd_edges.erase({p.second, p.first});
        add_edge(p.first, p.second);
        dfs(p.second);
    }
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) G[i].clear();
        odd_edges.clear();
        res.clear();
        for(int i = 0; i < m; i++) {
            int a, b; cin >> a >> b; a--, b--;
            G[a].insert(b);
            G[b].insert(a);
        }
        int mx = 0;
        fill(even, even + n, false);
        for(int i = 0; i < n; i++) {
            even[i] = (G[i].size() % 2 == 0);
            mx += even[i];
            if(!even[i]) for(int nxt : G[i]) odd_edges.insert({i, nxt});
        }
        for(int i = 0; i < n; i++) {
            if(even[i]) dfs(i);
        }
        for(int i = 0; i < n; i++) {
            for(int nxt : G[i]) if(i < nxt) res.push_back({i, nxt});
        }
        cout << mx << endl;
        for(auto p : res) cout << p.first + 1 << " " << p.second + 1 << endl;

    }

}