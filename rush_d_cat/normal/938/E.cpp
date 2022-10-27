#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
typedef long long LL;
const LL MOD = 1000000007;
const int N = 1000000+10;
int n;
LL f[N], a[N], b[N];
LL mpow(LL a, LL x) {
    if (x == 0) return 1;
    LL t = mpow(a, x / 2);
    if (x % 2 == 0) return t * t % MOD;
    return t * t % MOD * a % MOD;
}
void init() {
    f[0] = 1; 
    for (int i = 1; i < N; i ++) {
        f[i] = f[i-1] * (LL)i % MOD;
    }
}
int main() {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%lld", &a[i]); b[i] = a[i];
    }
    sort(b+1, b+1+n);
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        int cnt = n - (lower_bound(b+1, b+1+n, a[i]) - b) + 1; 
        if (b[n] == a[i]) continue;
        LL tmp = f[n] * mpow(cnt, MOD-2)  % MOD * a[i] % MOD;
        ans = (ans + tmp) % MOD;
    }
    printf("%lld\n", ans);
}