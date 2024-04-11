#include <bits/stdc++.h>
using namespace std;
#define N 110
int A[N][N];
int ans[N * N];

int main() {
    //freopen("1.in", "r", stdin);
    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    int cnt = 0;
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) A[i][j] = ++cnt;
    for(int i = 0; i < q; i ++) {
        int ty, x, y, val, l, r;
        scanf("%d", &ty);
        if(ty == 3) {
            scanf("%d%d%d", &x, &y, &val);
            int z = A[x][y];
            ans[z] = val;
        } else if(ty == 1) {
            scanf("%d", &r);
            int x = A[r][1];
            for(int i = 1; i < m; i ++) A[r][i] = A[r][i + 1];
            A[r][m] = x;
        } else if(ty == 2) {
            scanf("%d", &l);
            int x = A[1][l];
            for(int i = 1; i < n; i ++) A[i][l] = A[i + 1][l];
            A[n][l] = x;
        }
    }
    cnt = 0;
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            ++cnt;
            printf("%d", ans[cnt]);
            if(j < m) printf(" ");
        }
        puts("");
    }
}