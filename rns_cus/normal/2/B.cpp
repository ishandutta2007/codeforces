#include <bits/stdc++.h>
using namespace std;

#define N 1010

int n, a[N][N], b2[N][N], b5[N][N], dp[N][N], p2[N][N], p5[N][N];

int solve_1(int b[N][N], int p[N][N]) {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            dp[i][j] = 1e9;
            if (i == 1 && j == 1) {
                dp[i][j] = b[i][j];
                p[i][j] = -1;
                continue;
            }
            for (int k = 0; k < 2; k ++) {
                int ii = i, jj = j;
                if (k) ii --;
                else jj --;
                if (ii < 1 || jj < 1) continue;
                if (dp[ii][jj] < dp[i][j]) {
                    dp[i][j] = dp[ii][jj];
                    p[i][j] = k;
                }
            }
            dp[i][j] += b[i][j];
        }
    }
    return dp[n][n];
}

vector <int> vec;

void go(int p[N][N]) {
    vec.clear();
    int r = n, c = n;
    while (1) {
        int d = p[r][c];
        if (d < 0) break;
        vec.push_back(d);
        if (d) r --;
        else c --;
    }
    
    
    reverse(vec.begin(), vec.end());
    
}

int solve() {
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            int k = a[i][j], x = 0, y = 0;
            while (k % 2 == 0) k /= 2, x ++;
            while (k % 5 == 0) k /= 5, y ++;
            b2[i][j] = x, b5[i][j] = y;
        }
    }
    int x = solve_1(b2, p2), y = solve_1(b5, p5);
    if (x < y) go(p2);
    else go(p5);
    return min(x, y);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) scanf("%d", &a[i][j]);
    int r = -1, c = -1;
    for (int i = 1; i <= n && r < 0; i ++) for (int j = 1; j <= n && r < 0; j ++) if (!a[i][j]) r = i, c = j;
    if (r < 0) {
        printf("%d\n", solve());
        for (int i = 0; i < 2 * n - 2; i ++) putchar(vec[i] ? 'D' : 'R');
        return 0;
    }
    for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) if (!a[i][j]) a[i][j] = 10;
    if (solve()) {
        puts("1");
        for (int i = 1; i < r; i ++) putchar('D');
        for (int i = 1; i < c; i ++) putchar('R');
        for (int i = r; i < n; i ++) putchar('D');
        for (int i = c; i < n; i ++) putchar('R');
        puts(""); return 0;
    }
    else {
        puts("0");
        for (int i = 0; i < 2 * n - 2; i ++) putchar(vec[i] ? 'D' : 'R');
    }

    return 0;
}