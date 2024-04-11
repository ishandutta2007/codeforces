#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3;
bool solve(int u, int idx);

vector<int> adj[N];
int n, sz[N], f[N];
bool vis[N];

short dfs(int u, int p, int idx){
    sz[u] = 1;
    int sum = 2 * idx - 3;
    for(int to: adj[u]){
        if(to == p || vis[to]) continue;
        short x = dfs(to, u, idx);
        if(x != -1) return x;

        sz[u] += sz[to];
        if(sz[to] == f[idx - 1] || sz[to] == f[idx - 2]){
            vis[to] = true;
            int t = sz[to] == f[idx - 1] ? idx - 1 : idx - 2;
            if(!solve(u, sum - t)){
                vis[to] = false;
                return 0;
            }
            vis[to] = false;
            vis[u] = true;
            if(!solve(to, t)){
                vis[u] = false;
                return 0;
            }
            vis[to] = false;
            return 1;
        }
    }
    return -1;
}

bool solve(int u, int idx){
    if(idx <= 1) return true;
    return dfs(u, -1, idx) == 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    f[0] = 1;
    f[1] = 1;
    int idx = 1;
    while(f[idx] < n){
        f[idx + 1] = f[idx] + f[idx - 1];
        ++idx;
    }
    if(f[idx] != n){
        cout << "NO\n";
        return 0;
    }

    if(solve(1, idx)) cout << "YES\n";
    else cout << "NO\n";
}