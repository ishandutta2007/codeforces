#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e3 + 5;

int n, p[N];
std::vector<std::vector<int>> ans;

int main() {
    n = read();
    for (int i = 0; i < n; i++) {
        p[i] = read();
    }
    for (int k = 1; k <= n; k++) {
        if (n % 2 == 0 && k == n) { continue; }
        int t = 0;
        for (int i = 0; i < n; i++) {
            if (p[i] == k) { t = i; }
        }
        std::vector<int> res;
        if (k % 2 == 1) {
            if (t > 0) { res.push_back(t); }
            res.push_back(n - t - (k - 1));
            for (int i = 0; i < k - 1; i++) {
                res.push_back(1);
            }
        } else {
            for (int i = 0; i < k - 1; i++) {
                res.push_back(1);
            }
            res.push_back(n - (n - 1 - t) - (k - 1));
            if (t < n - 1) { res.push_back((n - 1) - t); }
        }
        if (res.size() > 1) {
            ans.push_back(res);
        }
        for (int i = 0, l = 0, r; i < res.size(); i++, l = r) {
            r = l + res[i];
            std::reverse(p + l, p + r);
        }
        std::reverse(p, p + n);
    }
    printf("%d\n", ans.size());
    for (auto vec : ans) {
        printf("%d", vec.size());
        for (auto i : vec) { printf(" %d", i); }
        printf("\n");
    }
    return 0;
}