#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, m;
char s[N];

int dp[1<<20], cnt[30][30];

int main() {
    scanf("%d %d %s", &n, &m, s);
    for (int i = 1; i < n; i ++) {
        int x = s[i-1] - 'a', y = s[i] - 'a';
        cnt[x][y] ++, cnt[y][x] ++;
    }
    n = 1 << m;
    dp[0] = 0;
    for (int i = 1; i < n; i ++) dp[i] = 1e9;
    for (int i = 1; i < n; i ++) {
        for (int k = 0; k < m; k ++) if (i >> k & 1) {
            int j = i ^ 1 << k;
            int sum = 0;
            for (int l = 0; l < m; l ++) {
                if (l == k) continue;
                if (j >> l & 1) sum += cnt[k][l];
                else sum -= cnt[k][l];
            }
            if (dp[j] < 1e9) dp[i] = min(dp[i], dp[j] + sum * __builtin_popcount(i));
        }
    }
    printf("%d\n", dp[n-1]);
}