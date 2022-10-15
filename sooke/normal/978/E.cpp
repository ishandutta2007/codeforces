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

const int maxN = 1005;

lol n, sum, vol, max, t;

int main() {
    n = read(), vol = read();
    for (int i = 1; i <= n; i++) {
        t = read();
        if (t == 0) { continue; } else
        if (t > 0) {
            sum += t, max = std::max(max, sum);
        } else {
            t = -t;
            if (sum - t >= 0) { sum -= t; }
            else { max += t - sum, sum = 0; }
        }
    }
    printf("%I64d\n", std::max(0ll, vol - max + 1));
}

// 5/1234fdsa/[s];3[].rt[]g.r