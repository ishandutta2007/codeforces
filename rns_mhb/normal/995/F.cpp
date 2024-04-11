#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int expmod(int x, int y) {
    int r = 1;
    while(y) {
        if(y & 1) r = 1ll * r * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return r;
}

#define N 3010

vector <int> adj[N];
int dp[N][N];

void dfs(int x) {
    for(int i = 0; i < N; i ++) dp[x][i] = 1;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        dfs(y);
        for(int j = 0; j < N; j ++) dp[x][j] = 1ll * dp[x][j] * dp[y][j] % mod;
    }
    for(int i = 1; i < N; i ++) {
        dp[x][i] += dp[x][i-1];
        if(dp[x][i] >= mod) dp[x][i] -= mod;
    }
}

int main() {
    int n, D;
    cin >> n >> D; D --;
    for(int i = 2, x; i <= n; i ++) {
        cin >> x;
        adj[x].push_back(i);
    }
    dfs(1);
    int ans = 0;
    for(int i = 0; i <= n; i ++) {
        int cur = dp[1][i], mo = 1;
        for(int j = 0; j <= n; j ++) if(j != i) {
            cur = 1ll * cur * (D-j) % mod;
            mo = 1ll * mo * (i-j) % mod;
        }
        if(cur < 0) cur += mod;
        if(mo < 0) mo += mod;
        ans = (ans + 1ll * cur * expmod(mo, mod-2)) % mod;
    }
    cout << ans << endl;
}