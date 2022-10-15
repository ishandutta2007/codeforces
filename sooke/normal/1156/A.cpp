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

inline int read() {
    char c = getchar(); int x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

int n, x, y, z, ans;

void infinite() {
    printf("Infinite\n");
    exit(0);
}

int main() {
    n = read(); x = read();
    for (int i = 2; i <= n; i++) {
        z = y; y = x; x = read();
        if (y == 1) {
            if (x == 2) { ans += 3; ans -= z == 3; }
            if (x == 3) { ans += 4; }
        } else if (y == 2) {
            if (x == 1) { ans += 3; }
            if (x == 3) { infinite(); }
        } else if (y == 3) {
            if (x == 1) { ans += 4; }
            if (x == 2) { infinite(); }
        }
    }
    printf("Finite\n%d\n", ans);
    return 0;
}