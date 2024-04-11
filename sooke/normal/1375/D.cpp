#include <bits/stdc++.h>

inline int read() {
    char c; int x; for (c = getchar(); !isdigit(c); c = getchar());
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return x;
}

const int N = 1e6 + 5;

int n, a[N], cnt[N];
std::vector<int> ans;

void solve() {
    while (true) {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) { ok = false; break; }
        }
        if (ok) { break; }
        for (int i = 0; i < n; i++) {
            cnt[a[i]]++;
        }
        int mex = 0;
        for (; cnt[mex] > 0; mex++);
        int p;
        if (mex < n) {
            p = mex;
        } else {
            for (int i = 0; i < n; i++) {
                if (a[i] != i) { p = i; break; }
            }
        }
        ans.push_back(p);
        for (int i = 0; i < n; i++) {
            cnt[a[i]]--;
        }
        a[p] = mex;
    }
}

int main() {
    for (int T = read(); T; T--) {
        n = read();
        for (int i = 0; i < n; i++) {
            a[i] = read();
        }
        ans.clear();
        solve();
        printf("%d\n", ans.size());
        for (auto i : ans) { printf("%d ", i + 1); }
        printf("\n");
    }
    return 0;
}