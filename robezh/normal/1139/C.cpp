#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50, mod = (int)1e9 + 7;

int n,k;
vector<int> G[N];
bool vis[N];

ll fp(ll x, ll k){
    if(k == 0) return 1;
    ll hf = fp(x, k/2);
    return k % 2 ? hf * hf % mod * x % mod: hf * hf % mod;
}

int dfs(int v) {
    vis[v] = true;
    int res = 1;
    for(int nxt : G[v]) if(!vis[nxt]) res += dfs(nxt);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    ll res = fp(n, k);
    for(int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(c) continue;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i = 0; i < n; i++) {
        if(vis[i]) continue;
        res -= fp(dfs(i), k);
        res %= mod;
    }
    res = (res % mod + mod) % mod;
    cout << res << endl;


}