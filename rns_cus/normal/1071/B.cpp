#include <bits/stdc++.h>
using namespace std;

#define N 2020

int n, k, dp[N][N], id[N][N];
char s[N][N];

struct cell{
    int r, c;
    cell(int r = 0, int c = 0) : r(r), c(c) {}
    bool operator < (const cell &p) const {
        if (s[r][c] == s[p.r][p.c]) {
            return min(id[r][c+1], id[r+1][c]) < min(id[p.r][p.c+1], id[p.r+1][p.c]);
        }
        return s[r][c] < s[p.r][p.c];
    }
} pa[N][N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i ++) scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[i][j] = max(dp[i-1][j] + (s[i-1][j] == 'a'), dp[i][j-1] + (s[i][j-1] == 'a'));
        }
    }
    if (2 * n - dp[n][n] - (s[n][n] == 'a') - 1 <= k) {
        for (int i = 0; i < 2 * n - 1; i ++) putchar('a');
        return 0;
    }
    for (int i = 1; i <= n + 1; i ++) id[i][n+1] = id[n+1][i] = 1e9;
    int R, C;
    for (int x = 2 * n; x >= 2; x --) {
        vector <cell> vec;
        for (int i = max(1, x - n); i <= min(n, x - 1); i ++) {
            vec.push_back(cell(i, x - i));
        }
        sort(vec.begin(), vec.end());
        int sz = vec.size();
        for (int i = 0; i < sz; i ++) {
            int r = vec[i].r, c = vec[i].c;
            id[r][c] = i;
            if (id[r][c+1] < id[r+1][c]) pa[r][c] = cell(r, c + 1);
            else pa[r][c] = cell(r + 1, c);
            if (x - dp[r][c] - 2 <= k) {R = r, C = c; goto last;}
        }
    }
    last:
        for (int i = 0; i < R + C - 2; i ++) putchar('a');
        while (R <= n && C <= n) {
            putchar(s[R][C]);
            cell p = pa[R][C];
            R = p.r, C = p.c;
        }
}