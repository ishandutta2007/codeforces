#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int powmod(int x, int y) {
    int ret = 1;
    while(y) {
        if(y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

void add(int &x, int y) {x += y; if(x >= mod) x -= mod;}

#define N 110

vector <int> adj[N];
int n, sz[N], dp[N][N][N], c[N][N];

void link(int x, int y) {
    for(int a=1; a<=sz[x]+sz[y]; a++) for(int k = 1; a+k-1<=sz[x]+sz[y]; k++) dp[0][a][k] = 0;
    for(int a = 1; a <= sz[x]; a ++) for(int k = 1; a + k - 1 <= sz[x]; k ++)
        for(int b = 1; b <= sz[y]; b ++) for(int h = 1; b + h - 1 <= sz[y]; h ++) {
            int mul = 1ll * dp[x][a][k] * dp[y][b][h] % mod;
            add(dp[0][a+b][k+h-1], mul);
            add(dp[0][a][k+h], 1ll * mul * b % mod);
        }
    swap(dp[x], dp[0]);
    sz[x] += sz[y];
}

void dfs(int x, int p) {
    sz[x] = 1;
    dp[x][1][1] = 1;
    for(int i = 0; i < adj[x].size(); i ++) {
        int y = adj[x][i];
        if(y == p) continue;
        dfs(y, x);
        link(x, y);
    }
}

int main() {
    for(int i = 0; i < N; i ++) c[0][i] = 0, c[i][0] = 1;
    for(int i = 1; i < N; i ++) for(int j = 1; j < N; j ++) c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
    scanf("%d", &n);
    for(int i = 1, x, y; i < n; i ++) {
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    for(int k = n; k; k --) {
        dp[1][0][k] = 0;
        for(int j = 1; j <= n; j ++) add(dp[1][0][k], 1ll * dp[1][j][k] * j % mod);
        dp[1][0][k] = 1ll * dp[1][0][k] * powmod(n, mod + k - 3) % mod;
    }
    for(int k = 2; k <= n; k ++) {
        for(int j = 1; j < k; j ++) {
            dp[1][0][k] = (dp[1][0][k] - 1ll * c[n-j][n-k] * dp[1][0][j]) % mod;
            if(dp[1][0][k] < 0) dp[1][0][k] += mod;
        }
    }
    for(int k = n; k; k --) printf("%d ", dp[1][0][k]); puts("");
}