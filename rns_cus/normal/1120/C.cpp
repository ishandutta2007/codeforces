#include <bits/stdc++.h>
using namespace std;

#define N 5050

int n, a, b, dp[N], h[N];
bool vis[N];
char s[N], t[N];

void prepare(char *p) {
    int m = strlen(p);
    for (int i = 1, j = 0; i < m; i ++) {
        while (j && p[i] != p[j]) j = h[j - 1];
        if (p[i] == p[j]) j ++;
        h[i] = j;
    }
}


int main() {    
    dp[0] = 0;
    scanf("%d %d %d %s", &n, &a, &b, s + 1);
    for (int i = 1; i <= n; i ++) {
        dp[i] = dp[i-1] + a;
        for (int j = i; j; j --) t[i-j] = s[j];
        t[i] = 0;
        prepare(t);
        for (int j = 0; j < i; j ++) vis[j] = 0;
        int mx = 0;
        for (int j = i - 1; j > 0; j --) {
            if (vis[j]) continue;
            int k = j + 1;
            while (2 * k > j + 1) {
                vis[k-1] = 1;
                k = h[k-1];
            }
            mx = max(mx, k); vis[k] = 1;
        }
        dp[i] = min(dp[i-mx] + b, dp[i]);
    }
    printf("%d\n", dp[n]);
}