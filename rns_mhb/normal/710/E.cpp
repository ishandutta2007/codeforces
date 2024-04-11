#include <bits/stdc++.h>
using namespace std;

#define N 10000005

typedef long long ll;
int n, x, y;
ll dp[N];

int main() {
    
    scanf("%d %d %d", &n, &x, &y);
    dp[1] = x;
    for (int i = 2; i <= n; i ++) {
        if (i & 1) dp[i] = min(dp[i-1] + x, dp[(i>>1)+1] + y + x);
        else dp[i] = min(dp[i-1] + x, dp[i>>1] + y);
    }
    printf("%I64d\n", dp[n]);
    return 0;
}