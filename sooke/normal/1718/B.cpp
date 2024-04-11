#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 105;

int n, a[N], _a[N], b[N], fib[N];
long long mask[N], _mask[N];

bool check() {
    for (int i = 1; i <= n; i++) {
        mask[i] = 0;
        for (int j = 43; j >= 0; j--) {
            if (a[i] >= fib[j]) {
                a[i] -= fib[j];
                mask[i] |= 1ll << j; j--;
            }
        }
        _mask[i] = 0;
        for (int j = 43; j >= 0; j--) {
            if (_a[i] > fib[j] || (j == 0 && _a[i] == 1)) {
                _a[i] -= fib[j];
                _mask[i] |= 1ll << j; j--;
            }
        }
    }
    for (int p = 1; p <= n; p++) {
        long long now = 0;
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (p == i) {
                if (_a[i] != 0) { flag = false; break; }
                if (now & _mask[i]) {
                    flag = false; break;
                } else {
                    now |= _mask[i];
                }
            } else {
                if (now & mask[i]) {
                    flag = false; break;
                } else {
                    now |= mask[i];
                }
            }
        }
        if (flag) {
            if (now == 2) { return true; }
            for (int i = 1; i <= 44; i++) {
                if (now == (1ll << i) - 1) { return true; }
            }
        }
    }
    return false;
}

int main() {
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 43; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 1; i <= n; i++) {
            a[i] = _a[i] = b[i] = read();
        }
        printf("%s\n", check() ? "Yes" : "No");
    }
    return 0;
}