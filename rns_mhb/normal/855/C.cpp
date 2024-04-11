#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

#define N 100010
#define M 11

int n, m, k, X;
vector <int> adj[N];
int dp[N][3][M], tmp[3][M];

void merge(int x, int y) {
    memset(tmp, 0, sizeof tmp);
    for(int i = 0; i <= X; i ++) for(int j = 0; i + j <= X; j ++) {
       tmp[0][i+j] = (tmp[0][i+j] + 1ll * dp[x][0][i] * (1ll * dp[y][0][j] + dp[y][1][j] + dp[y][2][j])) % mod;
       tmp[1][i+j] = (tmp[1][i+j] + 1ll * dp[x][1][i] * dp[y][0][j]) % mod;
       tmp[2][i+j] = (tmp[2][i+j] + 1ll * dp[x][2][i] * (dp[y][0][j] + dp[y][2][j])) % mod;
    }
    memcpy(dp[x], tmp, sizeof tmp);
}

void dfs(int x, int p) {
    dp[x][0][0] = k-1;
    dp[x][1][1] = 1;
    dp[x][2][0] = m-k;
    for(auto y : adj[x]) {
        if(y == p) continue;
        dfs(y, x);
        merge(x, y);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1, x, y; i < n; i ++) {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cin >> k >> X;
    dfs(1, 0);
    int ans = 0;
    for(int i = 0; i < 3; i ++) for(int j = 0; j <= X; j ++) (ans += dp[1][i][j]) %= mod;
    cout << ans << endl;
}