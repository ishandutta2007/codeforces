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

typedef long long lol;

inline lol read() {
    char c = getchar(); lol n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 600005;

int n;
lol x, y, a[maxN], b[maxN];

int main() {
    n = read();
    for (int i = 1; i <= n / 2; i++) { a[i] = read(); } b[n + 1] = 5e18;
    for (int i = 1; i <= n / 2; i++) {
        x = b[i - 1]; y = b[n + 2 - i];
        if (a[i] - y >= x) { b[i] = a[i] - y; b[n + 1 - i] = y; } else { b[i] = x; b[n + 1 - i] = a[i] - x; }
    }
    for (int i = 1; i <= n; i++) { printf("%I64d ", b[i]); }
    return 0;
} //