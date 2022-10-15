#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
} 

const int N = 1e6 + 5;

int n, dep[N];
std::pair<int, int> d[N];
std::map<int, int> f;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        d[i] = {read(), i};
    } std::sort(d, d + n);
    for (int i = 0; i < n; i++) {
        dep[d[i].second * 2 + 1] = i;
        f[i] = d[i].second * 2 + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        int x = i - d[i].first + 1;
        int u = f[x];
        dep[d[i].second * 2 + 2] = dep[u] - 1;
        if (f.count(dep[u] - 1) == 0) {
            f[dep[u] - 1] = d[i].second * 2 + 2;
        }
        printf("%d %d\n", d[i].second * 2 + 2, u);
    }
    for (int i = 1; i < n; i++) {
        printf("%d %d\n", d[i - 1].second * 2 + 1, d[i].second * 2 + 1);
    }
    return 0;
}