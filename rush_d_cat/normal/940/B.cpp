#include <iostream>
using namespace std;
typedef long long LL;
LL n, k, a, b;
int main() {
    cin >> n >> k >> a >> b;
    if (k == 1) {
        printf("%lld\n", (n-1)*a);
        return 0;
    }
    LL ans = 0;
    while (n != 1) {
        if (n % k == 0) {
            ans += min(b, a * (n - n/k) );
            n = n / k;
        } else {
            ans += (n % k) * a;
            n = n - n % k;
        }
        if (n == 0) {
            ans -= a;
            break;
        }
    }
    printf("%lld\n", ans);
}