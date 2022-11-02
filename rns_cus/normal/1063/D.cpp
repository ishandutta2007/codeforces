#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, l, r, k;
    cin >> n >> l >> r >> k;
    ll p = (l <= r) ? r - l + 1 : r + n - l + 1;
    if (n < 1e6) {
        int c;
        for (c = n; c >= 0; c --) {
            ll m = (k - 1) % (n + c) + 1;
            if (m <= min(c + p, 2 * p) && m >= max(p, 2 * p + c - n - 1)) break;
        }
        printf("%d\n", c);
    }
    else {
        ll ans = n - 1;
        if (k >= p && k <= 2 * p) {
            ans = k + 2 * n + 1 - 2 * p;
        }
        for (int d = 1; d < 1e6; d ++) {
            r = min(2 * n, min((k - p) / d, (k + 2 * n + 1 - 2 * p) / (d + 1)));
            l = max(n, max((k - 2 * p - 1) / d, (k + n - p - 1) / (d + 1)) + 1);
            if (r >= l) ans = max(ans, r);
        }
        printf("%I64d\n", ans - n);
    }
}