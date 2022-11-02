#include<bits/stdc++.h>
using namespace std;

#define N 20
#define M 100010

char s[N][M];
int n, m, dp[N+1][1<<N];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%s", s[i]);
    for(int i = 0; i < m; i ++) {
        int x = 0;
        for(int j = 0; j < n; j ++) if(s[j][i] == '1') x ^= 1 << j;
        dp[0][x] ++;
    }
    for(int i = 0; i < n; i ++) for(int j = i; j >= 0; j --) for(int k = (1<<n)-1; k >= 0; k --) dp[j+1][k^(1<<i)] += dp[j][k];
    int ans = 1e9;
    for(int i = (1<<n)-1; i >= 0; i --) {
        int cur = 0;
        for(int j = 0; j <= n; j ++) cur += dp[j][i] * min(j, n-j);
        if(cur < ans) ans = cur;
    }
    printf("%d\n", ans);
}