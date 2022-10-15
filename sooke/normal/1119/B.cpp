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

const int N = 1005;

int n, m;
long long now;
std::vector<int> a;

int main() {
    n = read(); m = read();
    for (int i = 1; i <= n; i++) {
        a.push_back(read()); now = 0;
        std::sort(a.begin(), a.end());
        for (int j = i - 1; j >= 0; j -= 2) { now += a[j]; }
        if (now > m) { printf("%d\n", i - 1); return 0; }
    }
    printf("%d\n", n);
    return 0;
} //