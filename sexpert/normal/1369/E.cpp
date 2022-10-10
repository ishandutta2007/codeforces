#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 1e5 + 10;
int pw[MAXN], ded[MAXN];
vector<ii> adj[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> pw[i];

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back({v, i + 1});
        adj[v].push_back({u, i + 1});
        pw[u]--;
        pw[v]--;
    }

    vector<int> ans;
    set<ii, greater<ii>> uwu;

    for(int i = 1; i <= n; i++)
        uwu.insert({pw[i], i});

    while(uwu.size()) {
        auto p = *uwu.begin();
        uwu.erase(uwu.begin());
        if(p.first < 0) {
            cout << "DEAD\n";
            return 0;
        }
        int u = p.second;
        ded[u] = 1;
        for(auto e : adj[u]) {
            if(ded[e.first])
                continue;
            int v = e.first;
            int idx = e.second;
            ans.push_back(idx);
            uwu.erase({pw[v], v});
            pw[v]++;
            uwu.insert({pw[v], v});
        }
    }
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for(auto x : ans)
        cout << x << " ";
    cout << '\n';
}