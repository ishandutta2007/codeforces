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
    char c = getchar(); long long x = 0; bool sgn = false;
    while (c < '0' || c > '9') { if (c == '-') { sgn = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return sgn ? -x : x;
}

const int N = 100005;

int n, m, k;
long long now, a[N], ans[N];
std::pair<long long, int> q[N];
std::priority_queue<long long, std::vector<long long>, std::greater<long long>> p;

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); }
    m = read();
    for (int i = 1; i <= m; i++) {
        long long l = read(), r = read();
        q[i] = {r - l + 1, i}; 
    }
    std::sort(a + 1, a + n + 1);
    std::sort(q + 1, q + m + 1);
    for (int i = 2; i <= n; i++) { p.push(a[i] - a[i - 1]); }
    long long x = 0, y; k = n;
    for (int i = 1; i <= m; i++) {
        y = x; x = q[i].first;
        while (p.size() && p.top() <= x) {
            now -= y; now += p.top();
            k--; p.pop();
        }
        now += k * (x - y);
        ans[q[i].second] = now;
    }
    for (int i = 1; i <= m; i++) { printf("%I64d ", ans[i]); }
    return 0;
} //