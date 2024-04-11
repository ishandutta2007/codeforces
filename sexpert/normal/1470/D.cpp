#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 3e5 + 10;
vector<int> adj[MAXN], adj2[MAXN];
int vi[MAXN], col[MAXN], d[MAXN], use[MAXN];

void dfs(int s) {
    vi[s] = 1;
    for(auto &v : adj[s]) {
        if(vi[v])
            continue;
        adj2[s].push_back(v);
        adj2[v].push_back(s);
        d[s]++;
        d[v]++;
        dfs(v);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        adj2[i].clear();
        vi[i] = d[i] = use[i] = 0;
        col[i] = -1;
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    set<pair<int, int>> st;
    vector<int> ord, guys;
    for(int i = 1; i <= n; i++) {
        if(vi[i] == 0) {
            cout << "NO\n";
            return;
        }
        st.insert({d[i], i});
    }
    while(st.size()) {
        auto p = *(st.begin());
        //cout << p.first << " " << p.second << '\n'; 
        st.erase(st.begin());
        int u = p.second;
        ord.push_back(u);
        d[u] = 0;
        for(auto &v : adj2[u]) {
            if(!d[v])
                continue;
            st.erase({d[v], v});
            d[v]--;
            st.insert({d[v], v});
        }
    }
    reverse(ord.begin(), ord.end());
    for(auto &x : ord) {
        //cout << "current = " << x << " ";
        //cout << '\n';
        if(!use[x]) {
            guys.push_back(x);
            for(auto &y : adj[x])
                use[y] = 1;
        }
    }
    cout << "YES\n";
    cout << guys.size() << '\n';
    for(auto &x : guys)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}