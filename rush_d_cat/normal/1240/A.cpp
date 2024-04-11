#include <iostream>
#include <algorithm>
using namespace std;
const int N = 200000 + 10;
typedef long long LL;

int t;
int n, p[N];
int x, a, y, b; LL k;
bool cmp(int x, int y) {
    return x > y;
}
LL gcd(LL x, LL y) {
    return y == 0 ? x : gcd(y, x%y);
}
LL lcm(LL x, LL y) {
    return x * y / gcd(x, y);
}
bool ok(int len) {
    LL ca = len / a;
    LL cb = len / b;
    LL cab = len / lcm(a, b);
    ca -= cab, cb -= cab;
    //printf("len = %d (%lld, %lld, %lld)\n", len, ca, cb, cab);
    int now = 0;
    LL sum = 0;
    for (int i = 1; i <= len; i ++) {
        if (i <= cab) {
            sum += p[i] / 100 * (x + y);
        } else if (i - cab <= ca) {
            sum += p[i] / 100 * x;
        } else if (i - cab - ca <= cb) {
            sum += p[i] / 100 * y;
        } 
    }
    //printf("sum = %lld ,k=%lld\n", sum, k);
    return sum >= k;
}
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &p[i]);
        }
        sort(p + 1, p + 1 + n, cmp);
        scanf("%d%d%d%d%lld", &x, &a, &y, &b, &k);
        if (x < y) {
            swap(x, y), swap(a, b);
        }
        int lef = 0, rig = n;
        if (!ok(rig)) {
            printf("-1\n");
            continue;
        }
        while(rig - lef > 1) {
            int mid = (lef + rig) >> 1;
            if (ok(mid)) rig = mid; else lef = mid;
        }
        printf("%d\n", rig);
    }
}