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

const int maxN = 1000005;

int m, k, n, s, max, now, a[maxN], b[maxN], c[maxN], d[maxN];

int main() {
    m = read(); k = read(); n = read(); s = read();
    for (int i = 1; i <= m; i++) { a[i] = read(); max = std::max(max, a[i]); }
    for (int i = 1; i <= s; i++) { b[i] = read(); max = std::max(max, b[i]); c[b[i]]++; }
    for (int i = 1; i <= max; i++) { now += c[i] == 0; }
    for (int i = 1, j = 1; i <= m; i++) {
        d[a[i]]++;
        if (c[a[i]] == d[a[i]]) { now++; }
        while (d[a[j]] > c[a[j]] && i - j + 1 > k) { d[a[j]]--; j++; }
        if (now == max && i - j + 1 >= k && (j - 1) / k + (m - i) / k + 1 >= n) {
            printf("%d\n", m - ((j - 1) / k + (m - i) / k + 1) * k);
            for (int p = 1; p <= (j - 1) % k; p++) { printf("%d ", p); }
            for (int p = j, used = i - j + 1 - k; p <= i; p++) {
                if (d[a[p]] > c[a[p]] && used >= 1) { d[a[p]]--; printf("%d ", p); used--; }
            }
            for (int p = i + 1; p <= i + (m - i) % k; p++) { printf("%d ", p); }
            return 0;
        }
    }
    printf("-1\n");
    return 0;
} //