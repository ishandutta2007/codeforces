#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
const int N = 200000+10;
LL max(LL x, LL y) {return x>y?x:y;}
LL min(LL x, LL y) {return x<y?x:y;}
LL n, d, b;
LL a[N], s[N];
LL f(int pos) {
    LL ans = 0;
    if (pos > n/2) {
        for (int i = 1; i <= pos; i ++) {
            LL supply = s[min(n, i*(d+1))];
            LL need = i * b;
            ans = max(ans, i - supply / b);
        }
    }
    if (pos <= n/2) {
        for (int i = n; i > pos; i --) {
            
            LL supply = s[n] - s[ max(0, n-d*(n-i+1)-(n-i)-1) ];
            LL need = (n-i+1) * b;
            ans = max(ans, n - i + 1 - supply / b);
        }
    }
    return ans;
}

int main() {
    scanf("%lld %lld %lld", &n, &d, &b);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]);
        s[i] = s[i-1] + a[i];
    }
    printf("%lld\n", max(f(1), f(n)));
    /*
    for (int i = 1; i <= 6; i ++) {
        printf("%lld\n", f(i));
    }
    int L = 1, R = n;
    while (R - L > 6) {
        int midL = (L + R) >> 1;
        int midR = (midL + R) >> 1;
        if (f(midL) < f(midR)) {
            R = midR;
        } else {
            L = midL;
        }
    }
    LL best = 1e12;
    for (int i = -6; i <= 6; i ++) {
        int cur = L + i;
        if (cur >= 1 && cur <= n)
            best = min(best, f(cur));
    }

    printf("%lld\n", best);
    */
}