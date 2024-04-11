#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 10;
int col[MAXN], mark[MAXN], leaf[MAXN], cnt[2];
vector<int> adj[MAXN];

void dfs(int s, int p = 0, int c = 0) {
    if(adj[s].size() == 1)
        cnt[c]++;
    for(auto v : adj[s])
        if(v != p)
            dfs(v, s, c ^ 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int leaves = 0;
    for(int u = 1; u <= n; u++) {
        if(adj[u].size() == 1) {
            mark[adj[u][0]] = 1;
            leaves++;
        }
    }
    int mx = n - leaves - 1;
    for(int u = 1; u <= n; u++)
        if(mark[u])
            mx++;
    dfs(1);
    int mn = 1;
    if(cnt[0] && cnt[1])
        mn = 3;
    cout << mn << " " << mx << '\n';
}