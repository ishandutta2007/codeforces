#include <bits/stdc++.h>
using namespace std;

#define N 1000100

int f(int n) {
    int rlt = 1;
    while (n) {
        while (n % 10 == 0) n /= 10;
        rlt *= n % 10, n /= 10;
    }
    return rlt;
}

int g[N], dp[N][10];

int main() {
    for (int i = 1; i < N; i ++) {
        if (i < 10) g[i] = i;
        else g[i] = g[f(i)];
        memcpy(dp[i], dp[i-1], 4 * 10);
        dp[i][g[i]] ++;
    }
    int q;
    scanf("%d", &q);
    while (q --) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", dp[r][k] - dp[l-1][k]);
    }

    return 0;
}