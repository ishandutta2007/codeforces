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
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const double eps = 1e-8;

int n, max = -1e9;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        int t = read();
        if (t >= 0) {
            if (std::abs(floor(sqrt(t)) * floor(sqrt(t)) - t) > eps) { max = std::max(max, t); }
        } else {
            max = std::max(max, t);
        }
    }
    std::cout << max;
    return 0;
} ////