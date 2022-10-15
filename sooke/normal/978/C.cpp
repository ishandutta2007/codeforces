#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

typedef long long lol;

inline lol read() {
    char c = getchar(); lol n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 200005;

int n, m;
lol a[maxN], sum[maxN];

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) { a[i] = read(), sum[i] = sum[i - 1] + a[i]; }
    for (; m; m--) {
        lol x = read(), pos = std::lower_bound(sum + 1, sum + n + 1, x) - sum;
        printf("%I64d %I64d\n", pos, x - sum[pos - 1]);
    }
    return 0;
}

// asj3940jfasd.432.4;.234./we./fd./dsa./f/.