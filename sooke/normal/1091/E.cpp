#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 500005;

long long n, l, r, now, cnt, sum, a[maxN], pre[maxN], suf[maxN];
std::priority_queue<int> q;
bool flag = true;

bool cmp(long long x, long long y) { return x > y; }

void solve(long long &res) {
    std::sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) { pre[i] = pre[i - 1] + a[i]; }
    while (!q.empty()) { q.pop(); } now = cnt = 0;
    for (int i = n; i >= 1; i--) {
        q.push(a[i]); now += a[i];
        while (!q.empty() && q.top() >= i - 1) { now -= q.top(); cnt++; q.pop(); }
        suf[i] = now + cnt * (i - 1);
    }
    for (int i = 1; i <= n; i++) { res = std::max(res, pre[i] - suf[i + 1] - 1ll * i * (i - 1)); }
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) { a[i] = read(); sum += a[i]; }
    solve(l);
    for (int i = 1; i <= n; i++) { a[i] = n - a[i]; }
    solve(r); r = n - r;
    for (int i = sum & 1; i <= n; i += 2) {
        if (l <= i && i <= r) { flag = false; printf("%d ", i); }
    }
    if (flag) { printf("-1\n"); }
    return 0;
} // //