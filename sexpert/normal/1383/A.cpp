#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[30];
int vis[30];

void dfs(int s) {
    vis[s] = 1;
    for(auto v : adj[s]) {
        if(!vis[v])
            dfs(v);
    }
}

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<int> cnt(300, 0);
    for(int i = 0; i < 30; i++)
        adj[i].clear();
    for(int i = 0; i < n; i++) {
        if(s[i] > t[i]) {
            cout << "-1\n";
            return;
        }
        if(s[i] == t[i])
            continue;
        adj[s[i] - 'a'].push_back(t[i] - 'a');
        adj[t[i] - 'a'].push_back(s[i] - 'a');
    }
    fill(vis, vis + 30, 0);
    int ans = 20;
    for(int i = 0; i < 20; i++) {
        if(!vis[i]) {
            dfs(i);
            ans--;
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