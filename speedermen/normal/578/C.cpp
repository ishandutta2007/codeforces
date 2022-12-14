#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1 << 18;

int a[MaxN];

int main() {
//    freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    long double L = -1e+6, R = +1e+6, ans = 1e+42;
    for (int it = 0; it < 100; ++it) {
        auto func = [&](long double x) {
            long double res = 0.0, cur;
            cur = 0.0;
            for (int i = 1; i <= n; ++i) {
                cur += a[i] - x;
                if (cur < 0) {
                    cur = 0;
                }
                if (res < cur) {
                    res = cur;
                }
            }
            cur = 0.0;
            for (int i = 1; i <= n; ++i) {
                cur -= a[i] - x;
                if (cur < 0) {
                    cur = 0;
                }
                if (res < cur) {
                    res = cur;
                }
            }
            return res;
        };
        long double dL = L + (R - L) / 3, dR = R - (R - L) / 3;
        long double fdL = func(dL), fdR = func(dR);
        if (fdL < fdR) {
            R = dR;
        } else {
            L = dL;
        }
        ans = min(ans, min(fdL, fdR));
    }
    cout.precision(10);
    cout << fixed << ans << '\n';
    return 0;
}