#include <cstdio>

typedef long long LL;

LL n, ans;

int main() {
    scanf("%I64d", &n);
    LL t = 1, tp = 1;
    while(1) {
        t *= 10;
        if(n < t) {
            ans += tp * (n - t/10 + 1);
            break;
        } else ans += tp * (t - t / 10);
        tp ++;
    }
    printf("%I64d\n", ans);
    return 0;
}