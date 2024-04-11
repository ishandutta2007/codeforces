#include <bits/stdc++.h>
using namespace std;

#define N 300300
#define K 20

int n, q, a[N], dp[N][K], nxt[N][K];

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for (int k = 0; k < K; k ++) {
        int cur = n + 1;
        for (int i = n; i; i --) {
            nxt[i][k] = n + 1;
            if (a[i] >> k & 1) nxt[i][k] = cur, cur = i;
        }
    }
    for (int i = n; i; i --) {
        for (int k = 0; k < K; k ++) {
            if (a[i] >> k & 1) dp[i][k] = i;
            else {
                dp[i][k] = n + 1;
                for (int l = 0; l < K; l ++)
                    if (nxt[i][l] <= n) dp[i][k] = min(dp[i][k], dp[nxt[i][l]][k]);
            }
        }
    }
    while (q --) {
        int x, y;
        scanf("%d %d", &x, &y);
        int rlt = 0;
        for (int k = 0; k < K; k ++)
        if (a[y] >> k & 1) {
            if (y >= dp[x][k]) rlt = 1;
        }
        puts(rlt ? "Shi" : "Fou");
    }


    return 0;
}