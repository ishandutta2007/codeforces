#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 2e5 + 10;
vector<int> adj[MAXN];
int deg[MAXN], par[MAXN], cnt[MAXN];

void dfs(int s, int p = 0) {
    par[s] = p;
    for(auto v : adj[s])
        if(v != p)
            dfs(v, s);
}

void solve() {
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        adj[i].clear();
        deg[i] = par[i] = cnt[i] = 0;
    }
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    if(n == 2) {
        cout << (k == 1 ? 1 : 0) << '\n';
        return;
    }
    if(k == 1) {
        cout << n - 1 << '\n';
        return;
    }
    int rt = 0;
    for(int i = 1; i <= n; i++)
        if(deg[i] > 1)
            rt = i;
    dfs(rt);
    
    for(int i = 1; i <= n; i++) {
        if(deg[i] == 1)
            cnt[par[i]]++;
    }
    set<pair<int, int>> proc;
    for(int i = 1; i <= n; i++) {
        if(cnt[i])
            proc.insert({-cnt[i], i});
    }
    int ans = 0;
    while(proc.size() && (*proc.begin()).first <= -k) {
        int u = (*proc.begin()).second;
        deg[u] -= k;
        cnt[u] -= k;
        ans++;
        proc.erase(proc.begin());
        if(cnt[u])
            proc.insert({-cnt[u], u});
        if(deg[u] == 1) {
            int pa = 0;
            for(auto v : adj[u]) {
                if(deg[v] == 1)
                    continue;
                pa = v;
            }
            if(pa == 0)
                continue;
            proc.erase({-cnt[pa], pa});
            cnt[pa]++;
            proc.insert({-cnt[pa], pa});
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
        solve();
}