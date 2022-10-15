#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

inline int read() {
    char c = getchar(); int n = 0; bool f = false;
    while (c < '0' || c > '9') { if (c == '-') { f = true; } c = getchar(); }
    while (c >= '0' && c <= '9') { n = (n << 1) + (n << 3) + (c & 15); c = getchar(); }
    return f ? -n : n;
}

const int maxN = 100005;

int n, ans, a[maxN];
std::priority_queue<int> max, maxDel;
std::priority_queue<int, std::vector<int> , std::greater<int> > min, minDel;

int main() {
    n = read();
    for (int i = 1, j = 1; i <= n; i++) {
        a[i] = read(); max.push(a[i]); min.push(a[i]);
        while (max.top() - min.top() > 1) {
            maxDel.push(a[j]); minDel.push(a[j++]);
            while (maxDel.size() && max.top() == maxDel.top()) { max.pop(); maxDel.pop(); }
            while (minDel.size() && min.top() == minDel.top()) { min.pop(); minDel.pop(); }
        }
        ans = std::max(ans, i - j + 1);
    }
    printf("%d\n", ans);
    return 0;
}