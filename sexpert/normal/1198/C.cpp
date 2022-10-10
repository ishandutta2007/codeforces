#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 3e5 + 5;
vector<ii> adj[MAXN];
set<int> paint[MAXN];

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= 3*n; i++) {
        adj[i].clear();
        paint[i].clear();
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }
    set<int> iset;
    vector<int> match;
    for(int i = 1; i <= 3*n; i++) {
        if(paint[i].empty()) {
            iset.insert(i);
            for(auto p : adj[i])
                paint[p.first].insert(i);
            if(iset.size() >= n)
                break;
        }
        else {
            int u = *paint[i].begin();
            iset.erase(u);
            for(int j = 0; j < adj[u].size(); j++) {
                paint[adj[u][j].first].erase(u);
                if(adj[u][j].first == i)
                    match.push_back(adj[u][j].second + 1);
            }
            if(match.size() >= n)
                break;
        }
    }
    if(iset.size() == n) {
        cout << "IndSet\n";
        for(auto x : iset)
            cout << x << " ";
        cout << '\n';
        return;
    }
    if(match.size() == n) {
        cout << "Matching\n";
        for(auto x : match)
            cout << x << " ";
        cout << '\n';
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}