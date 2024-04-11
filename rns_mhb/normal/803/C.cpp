#include <bits/stdc++.h>
using namespace std;

template <class T> bool chkmax(T &a, T b) { return a < b ? 1, a = b : 0; }
typedef long long ll;
ll n, k, ans;

int main() {
    scanf("%I64d %I64d", &n, &k);
    if (k > 1000000 || k < 1000000 && k * (k + 1) > 2 * n) {
        return puts("-1"), 0;
    }
    for (ll d = 1; d * d <= n; d ++) {
        if (n % d == 0) {
            if (n / d >= k * (k + 1) / 2) chkmax(ans, d);
            if (d >= k * (k + 1) / 2) chkmax(ans, n / d);
        }
    }
    for (int i = 1; i <= k; i ++) {
        if (i < k) printf("%I64d ", i * ans);
        else printf("%I64d", n);
        n -= i * ans;
    }
    return 0;
}