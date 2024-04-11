#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

int n, m, mod, k;
int sz[N];
int vis[N];

vector<int> G[N];

int dfs(int v) {
    vis[v] = true;
    int res = 1;
    for(int nxt : G[v]) if(!vis[nxt]) res += dfs(nxt);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> mod;
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) if(!vis[i]) sz[++k] = dfs(i);
    if(k == 1) return cout << 1 % mod << endl, 0;
    ll res = 1;
    for(int i = 1; i <= k - 2; i++) res = (res * n) % mod;
    for(int i = 1; i <= k; i++) res = (res * sz[i]) % mod;
    cout << res << endl;

}