#include <iostream>
using namespace std;
typedef long long LL;
const int N = 100000+10;
int n, c;
LL a[N], dp[N], sum;
typedef pair<int, int> pii;
pii que[N]; int head = 1, tail = 1;
int main() {
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]), sum += a[i];
    if (c == 0) return !printf("0\n");
    for (int i = 1; i <= n; i ++) {
        while (head <= tail && que[tail].first >= a[i]) tail --;
        que[++tail] = make_pair(a[i], i);
        while (head <= tail && que[head].second <= i - c) head ++;   
        if (i >= c)
            dp[i] = dp[i-c] + que[head].first;
        dp[i] = max(dp[i-1], dp[i]);
    }
    printf("%lld\n", sum-dp[n]);
}