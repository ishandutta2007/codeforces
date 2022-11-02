#include<bits/stdc++.h>
using namespace std;

#define N 200010

vector <int> adj[N];
int sz[N], ez[N], d[N], a[N];

void dfs(int x, int p) {
    sz[x] = ez[x] = 1;
    d[x] = d[p] ^ 1;
    for(auto y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        sz[x] += sz[y];
        ez[p] += ez[y];
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1, x, y; i < n; i ++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    int A[2] = {};
    for(int i = 1; i <= n; i ++) A[d[i]] ++;
    int mod = 1e9 + 7, ans = 0;
    for(int i = 1; i <= n; i ++) {
        int val = n;
        for(auto x : adj[i]) {
            if(sz[x] > sz[i]) continue;
            val = (val + 1ll * (sz[x]-2*ez[x]) * (n-sz[x])) % mod;
        }
        val = (val + 1ll * (2*(A[d[i]]-ez[i])-(n-sz[i])) * sz[i]) % mod;
        ans = (ans + 1ll * val * a[i]) % mod;
    }
    if(ans < 0) ans += mod;
    cout << ans << endl;
}