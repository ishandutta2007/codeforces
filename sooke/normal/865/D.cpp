#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

int n;
long long ans;
std::priority_queue<int> que;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        int x = read();
        que.push(-x);
        if (que.top() + x > 0) {
            ans += que.top() + x;
            que.push(-x); que.pop();
        }
    }
    printf("%lld\n", ans);
    return 0;
}