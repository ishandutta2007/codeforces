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

const int N = 300005;

int n, a[N];
long long k, ans;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        a[i] = read();
        if (k * 2 <= a[i]) {
            ans += k; a[i] -= k * 2; k = 0;
        } else {
            ans += a[i] / 2; k -= a[i] / 2; a[i] %= 2;
        }
        ans += a[i] / 3; a[i] %= 3; k += a[i];
    }
    printf("%I64d\n", ans);
    return 0;
}