#include <bits/stdc++.h>

inline long long read() {
    char c; long long x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int mod = 1e9 + 7;

inline int add(int x, int y) {
    return x + y >= mod ? x + y - mod : x + y;
}
inline int sub(int x, int y) {
    return x - y >= 0 ? x - y : x - y + mod;
}
inline int power(int x, int y) {
    int res = 1;
    for (; y; y >>= 1, x = 1ll * x * x % mod) {
        if (y & 1) { res = 1ll * res * x % mod; }
    }
    return res;
}

const int N = 1e6 + 5;

int n, pwr[N], cnt[N];
long long a[N];

int main() {
    pwr[0] = 1;
    for (int i = 1; i <= 62; i++) {
        pwr[i] = add(pwr[i - 1], pwr[i - 1]);
    }
    for (int T = read(); T; T--) {
        for (int i = 0; i <= 62; i++) {
            cnt[i] = 0;
        }
        n = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
            for (int j = 0; j <= 62; j++) {
                cnt[j] += a[i] >> j & 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = 0, y = 0;
            for (int j = 0; j <= 62; j++) {
                if (a[i] >> j & 1) {
                    x = (x + 1ll * pwr[j] * cnt[j]) % mod;
                    y = (y + 1ll * pwr[j] * n) % mod;
                } else {
                    y = (y + 1ll * pwr[j] * cnt[j]) % mod;
                }
            }
            ans = (ans + 1ll * x * y) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}