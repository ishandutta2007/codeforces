#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int inf = 1e9;
const int N = 3e3 + 5;

int n, ka, kb, ans, a[N], b[N], col[N];
std::priority_queue<std::pair<int, int>> quea, queb, que1, que2;

int main() {
    n = read(); ka = read(); kb = read();
    for (int i = 0; i < n; i++) {
        a[i] = read(); quea.push({a[i], i});
    }
    for (int i = 0; i < n; i++) {
        b[i] = read(); queb.push({b[i], i});
    }
    while (ka > 0 || kb > 0) {
        for (; !quea.empty() && col[quea.top().second] != 0; quea.pop());
        for (; !queb.empty() && col[queb.top().second] != 0; queb.pop());
        int res = -inf, opt, i, j;
        if (ka > 0) {
            if (!quea.empty()) {
                if (res < quea.top().first) {
                    res = quea.top().first;
                    opt = 1;
                }
            }
            if (!queb.empty() && !que1.empty()) {
                if (res < queb.top().first + que1.top().first) {
                    res = queb.top().first + que1.top().first;
                    opt = 2;
                }
            }
        }
        if (kb > 0) {
            if (!queb.empty()) {
                if (res < queb.top().first) {
                    res = queb.top().first;
                    opt = 3;
                }
            }
            if (!quea.empty() && !que2.empty()) {
                if (res < quea.top().first + que2.top().first) {
                    res = quea.top().first + que2.top().first;
                    opt = 4;
                }
            }
        }
        ans += res;
        if (opt == 1) {
            ka--;
            i = quea.top().second;
            col[i] = 1;
            quea.pop();
            que2.push({b[i] - a[i], i});
        }
        if (opt == 2) {
            ka--;
            i = queb.top().second;
            j = que1.top().second;
            col[i] = 2;
            queb.pop();
            que1.push({a[i] - b[i], i});
            col[j] = 1;
            que1.pop();
            que2.push({b[j] - a[j], j});
        }
        if (opt == 3) {
            kb--;
            i = queb.top().second;
            col[i] = 2;
            queb.pop();
            que1.push({a[i] - b[i], i});
        }
        if (opt == 4) {
            kb--;
            i = quea.top().second;
            j = que2.top().second;
            col[i] = 1;
            quea.pop();
            que2.push({b[i] - a[i], i});
            col[j] = 2;
            que2.pop();
            que1.push({a[j] - b[j], j});
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        if (col[i] == 1) { printf("%d ", i + 1); }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        if (col[i] == 2) { printf("%d ", i + 1); }
    }
    printf("\n");
    return 0;
}