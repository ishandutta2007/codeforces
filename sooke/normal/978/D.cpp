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

const int maxN = 100005;

int n;
lol ans = maxN, a[maxN];

inline lol check(lol x, lol y) {
    int res = 0;
    for (int i = 3; i <= n; i++) {
        int d = x + (y - x) * (i - 1);
        if (a[i] == d - 1 || a[i] == d + 1) { res++; }
        else if (a[i] == d) { ; }
        else { return maxN; } 
    }
    return res;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            ans = std::min(ans, check(a[1] + i, a[2] + j) + (i != 0) + (j != 0));
        }
    }
    if (ans <= n) { printf("%I64d\n", ans); } else { printf("-1\n"); }
    return 0;
}

// a123./12./.d/.as/./4././12./3/