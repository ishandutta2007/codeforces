#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
const LL INF = 1e14 + 7;
const LL N = 1002;
LL n, w, b, x, sum;
LL dp[N][10002], mx[N][10002], c[N], cost[N];
LL head = 1, tail = 0;
pair<LL, LL> que[10002];
LL max(LL x, LL y) {return x > y ? x : y;}
int main() {
    scanf("%lld %lld %lld %lld", &n, &w, &b, &x);
    for (LL i = 1; i <= n; i ++) scanf("%lld", &c[i]);
    for (LL i = 1; i <= n; i ++) scanf("%lld", &cost[i]);
    
    for (LL i = 0; i < N; i ++) 
        for (LL j = 0; j < 10002; j ++) 
            mx[i][j] = dp[i][j] = -INF;
    
    dp[0][0] = w;
    for (LL i = 0; i < 10002; i ++) 
        mx[0][i] = w;  
    
    for (LL i = 1; i <= n; i ++) {
        sum += c[i];

        head = 1, tail = 0;
        for (LL j = 0; j <= sum; j ++) {                             
            while (head <= tail && mx[i-1][j] >= que[tail].first) tail --;
            que[++tail].first = mx[i-1][j]; que[tail].second = j;   
            while (que[head].second < j - c[i]) head ++;
            LL maxv = que[head].first; // mx[i-1][j-c[i]] ~ mx[i-1][j]
            for (LL k = max(j-c[i],0); k <= j; k ++) maxv = max(maxv, mx[i-1][k]);
            if (maxv - j * cost[i] < 0) continue;
            dp[i][j] = min( maxv - j * cost[i] + x, w + b * j );
        }
        for (LL j = 0; j <= sum; j ++) {
            mx[i][j] = dp[i][j] + j * cost[i+1];
        }
    }
    LL ans = -1;
    for (LL i = 0; i <= sum; i ++)
        if (dp[n][i] >= 0) ans = i;
    printf("%lld\n", ans);
}