#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int T, a, b, c, d;
__int128_t ans;

inline __int128_t calc(__int128_t k) {
    return k * a - k * (k - 1) / 2 * b * d;
}

int main() {
    for (int T = read(); T; T--) {
        a = read(); b = read(); c = read(); d = read();
        if (a > 1ll * b * c) { printf("-1\n"); continue; }
        ans = 0;
        for (long long l = 0, r = c / d + 1, midl, midr; l <= r; ) {
            midl = l + (r - l) / 3;
            __int128_t resl = calc(midl);
            midr = r - (r - l) / 3;
            __int128_t resr = calc(midr);
            ans = std::max(ans, std::max(resl, resr));
            if (resl <= resr) {
                l = midl + 1;
            } else {
                r = midr - 1;
            }
        }
        printf("%lld\n", (long long) ans);
    }
    return 0;
}