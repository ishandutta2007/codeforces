#include <bits/stdc++.h>
using namespace std;

#define N 105

int n, k;
bool vis[N][N];

int main() {
    scanf("%d %d", &n, &k);
    if (k > n * n) return puts("-1"), 0;
    for (int i = 1; i <= n && k; i ++)
    for (int j = 1; j <= n && k; j ++) {
        if (vis[i][j]) continue;
        if (i == j) {
            vis[i][j] = 1;
            k --;
        }
        else {
            if (k >= 2) {
                vis[i][j] = vis[j][i] = 1;
                k -= 2;
            }
            else {
                vis[i+1][i+1] = 1;
                k --;
            }
        }
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) printf("%d ", vis[i][j]);
        puts("");
    }
    return 0;
}