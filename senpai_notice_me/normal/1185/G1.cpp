#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50 + 5;

const int MOD = (int) 1e9 + 7;

int dp[MAXN][MAXN][MAXN][3];
bool vis[MAXN][MAXN][MAXN][3];

int getDp(int x, int y, int z, int t) {
    if (x + y + z == 1) {
        return (x && t == 0) || (y && t == 1) || (z && t == 2);
    }
    if (vis[x][y][z][t]) return dp[x][y][z][t];
    vis[x][y][z][t] = true;
    int &res = dp[x][y][z][t];
    int tt;
    if (t == 0) {
        tt = x;
        --x;
    } else if (t == 1) {
        tt = y;
        --y;
    } else {
        tt = z;
        --z;
    }
    if (t != 0 && x) {
        res = (res + (long long) tt * getDp(x, y, z, 0)) % MOD;
    }
    if (t != 1 && y) {
        res = (res + (long long) tt * getDp(x, y, z, 1)) % MOD;
    }
    if (t != 2 && z) {
        res = (res + (long long) tt * getDp(x, y, z, 2)) % MOD;
    }
    return res;
}

int getDp(int x, int y, int z) {
    if (x + y + z == 0) return 1;
    int res = 0;
    if (x) res = (res + getDp(x, y, z, 0)) % MOD;
    if (y) res = (res + getDp(x, y, z, 1)) % MOD;
    if (z) res = (res + getDp(x, y, z, 2)) % MOD;
    return res;
}

int n, T;
int t[MAXN], g[MAXN];

int main() {
    scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", t + i, g + i); --g[i];
    }
    
    // cerr << getDp(0, 0, 1) << endl;
    
    int ans = 0;
    
    for (int S = 0; S < (1 << n); ++S) {
        int a = 0, b = 0, c = 0, sum = 0;
        for (int i = 1; i <= n; ++i) if (S & (1 << (i - 1))) {
            sum += t[i];
            if (g[i] == 0) ++a;
            else if (g[i] == 1) ++b;
            else ++c;
        }
        
        if (sum == T) {
            ans = (ans + getDp(a, b, c)) % MOD;
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}