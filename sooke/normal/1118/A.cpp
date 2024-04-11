#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

inline long long read() {
    char c = getchar(); long long x = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return f ? -x : x;
}

long long n, x, y;

int main() {
    for (int q = read(); q; q--) {
        n = read(); x = read(); y = read();
        if (x * 2 < y) { printf("%I64d\n", n * x); }
        else { printf("%I64d\n", n / 2 * y + (n % 2) * x); }
    }
    return 0;
}