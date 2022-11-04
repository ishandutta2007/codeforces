#include <bits/stdc++.h>

using namespace std;

const int MAXN = 50 + 5;

int n;
char s[MAXN][MAXN];
int cnt[MAXN][MAXN];

int cntOf(int xl, int xr, int yl, int yr) {
    return cnt[xr][yr] - cnt[xl - 1][yr] - cnt[xr][yl - 1] + cnt[xl - 1][yl - 1];
}

int dp[MAXN][MAXN][MAXN][MAXN];
bool vis[MAXN][MAXN][MAXN][MAXN];

int solve(int xl, int xr, int yl, int yr) {
    if (vis[xl][xr][yl][yr]) return dp[xl][xr][yl][yr];
    vis[xl][xr][yl][yr] = true;
    if (cntOf(xl, xr, yl, yr) == 0) return dp[xl][xr][yl][yr] = 0;
    int &res = dp[xl][xr][yl][yr];
    res = max(xr - xl + 1, yr - yl + 1);
    if (cntOf(xl, xr, yl, yr) == (xr - xl + 1) * (yr - yl + 1)) return res;
    for (int mid = xl; mid < xr; ++mid) {
        res = min(res, solve(xl, mid, yl, yr) + solve(mid + 1, xr, yl, yr));
    }
    for (int mid = yl; mid < yr; ++mid) {
        res = min(res, solve(xl, xr, yl, mid) + solve(xl, xr, mid + 1, yr));
    }
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s[i] + 1);
        for (int j = 1; j <= n; ++j) {
            cnt[i][j] = cnt[i - 1][j] + cnt[i][j - 1] - cnt[i - 1][j - 1] + (s[i][j] == '#');
        }
    }
    
    printf("%d\n", solve(1, n, 1, n));
    
    return 0;
}