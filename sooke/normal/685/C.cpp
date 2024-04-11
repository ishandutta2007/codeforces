#include <bits/stdc++.h>

const long long inf = 3e18;
const int N = 1e5 + 5;

int T, n;
long long l0, r0, l1, r1, l2, r2, l3, r3;
long long ans, ansx, ansy, ansz, x[N], y[N], z[N];

void solve(long long w1, long long w2, long long w3) {
    ansx = (w1 + w2) / 2; ansy = (w1 + w3) / 2; ansz = (w2 + w3) / 2;
}
bool check(long long mid) {
    for (int o = 0; o < 2; o++) {
        l0 = l1 = l2 = l3 = -inf;
        r0 = r1 = r2 = r3 = inf;
        for (int i = 0; i < n; i++) {
            l0 = std::max(l0, x[i] + y[i] + z[i] - mid);
            r0 = std::min(r0, x[i] + y[i] + z[i] + mid);
            l1 = std::max(l1, x[i] + y[i] - z[i] - mid);
            r1 = std::min(r1, x[i] + y[i] - z[i] + mid);
            l2 = std::max(l2, x[i] - y[i] + z[i] - mid);
            r2 = std::min(r2, x[i] - y[i] + z[i] + mid);
            l3 = std::max(l3, -(x[i] - y[i] - z[i] + mid));
            r3 = std::min(r3, -(x[i] - y[i] - z[i] - mid));
        }
        if ((l0 % 2 + 2) % 2 != o) { l0++; }
        if ((l1 % 2 + 2) % 2 != o) { l1++; }
        if ((l2 % 2 + 2) % 2 != o) { l2++; }
        if ((l3 % 2 + 2) % 2 != o) { l3++; }
        if (l0 > r0 || l1 > r1 || l2 > r2 || l3 > r3) { continue; }
        if (l1 + l2 + l3 > r0) { continue; }
        long long k1 = (r1 - l1) / 2 * 2;
        long long k2 = (r2 - l2) / 2 * 2;
        long long k3 = (r3 - l3) / 2 * 2;
        if (l1 + l2 + l3 >= l0) {
            solve(l1, l2, l3);
            return true;
        } else if (l1 + l2 + l3 + k1 >= l0) {
            solve(l0 - l2 - l3, l2, l3);
            return true;
        } else if (l1 + l2 + l3 + k1 + k2 >= l0) {
            solve(l1 + k1, l0 - (l1 + k1) - l3, l3);
            return true;
        } else if (l1 + l2 + l3 + k1 + k2 + k3 >= l0) {
            solve(l1 + k1, l2 + k2, l0 - (l1 + k1) - (l2 + k2));
            return true;
        }
    }
    return false;
}

int main() {
    for (scanf("%d", &T); T; T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
        }
        for (long long l = 0, r = inf, mid; l <= r; ) {
            mid = l + r >> 1;
            if (check(mid)) {
                r = mid - 1; ans = mid;
            } else {
                l = mid + 1;
            }
        }
        check(ans);
        printf("%lld %lld %lld\n", ansx, ansy, ansz);
    }
    return 0;
}