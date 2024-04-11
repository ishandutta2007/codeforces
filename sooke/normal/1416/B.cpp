#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e5 + 5;

int n, ave, a[N];

struct Answer {
    int i, j, x;
};

std::vector<Answer> ans;

bool check() {
    for (int i = 1; i <= n; i++) {
        if (a[i] != ave) { return false; }
    }
    return true;
}

int main() {
    for (int T = read(); T; T--) {
        n = read(); ave = 0;
        for (int i = 1; i <= n; i++) {
            a[i] = read(); ave += a[i];
        }
        ave /= n; ans.clear();
        for (int i = 2; i <= n; i++) {
            ans.push_back((Answer) {1, i, (i - a[i] % i) % i});
            a[1] -= (i - a[i] % i) % i;
            a[i] += (i - a[i] % i) % i;
            ans.push_back((Answer) {i, 1, a[i] / i});
            a[1] += a[i]; a[i] = 0;
        }
        for (int i = 2; i <= n; i++) {
            ans.push_back((Answer) {1, i, ave});
            a[1] -= ave; a[i] += ave;
        }
        if (!check()) { printf("-1\n"); continue; }
        printf("%d\n", ans.size());
        for (auto i : ans) {
            printf("%d %d %d\n", i.i, i.j, i.x);
        }
    }
    return 0;
}