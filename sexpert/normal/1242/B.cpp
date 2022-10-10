    #include <bits/stdc++.h>
    using namespace std;
     
    int n, m;
    const int MAXN = 1e5 + 5;
    set<int> adj[MAXN], unused;
    int comp[MAXN], sz[MAXN];
     
    void search(int s, int c) {
        queue<int> q({s});
        comp[s] = c;
        sz[c]++;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            vector<int> seen;
            for(auto x : unused) {
                if(adj[u].count(x) || comp[x])
                    continue;
                comp[x] = c;
                sz[c]++;
                seen.push_back(x);
                q.push(x);
            }
            for(auto x : seen)
                unused.erase(x);
            seen.clear();
        }
    }
     
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cin >> n >> m;
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            adj[x].insert(y);
            adj[y].insert(x);
        }
        for(int i = 1; i <= n; i++)
            unused.insert(i);
        int cc = 0;
        for(int i = 1; i <= n; i++) {
            if(!comp[i]) {
                cc++;
                search(i, cc);
            }
        }
        cout << cc - 1 << '\n';
    }