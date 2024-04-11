#include <bits/stdc++.h>

inline int read() {
    char c, _c; int x; for (c = _c = getchar(); !isdigit(c); c = getchar()) { _c = c; }
    for (x = 0; isdigit(c); c = getchar()) { x = x * 10 + c - '0'; } return _c == '-' ? -x : x;
}

const int N = 1e6 + 5;

int n, m, k, a[N], b[N], pl[N], pr[N], p[N], tb[N], gl, gr;
long long ss[N], pre[N], suf[N];
std::vector<int> al[N], ap[N], ar[N];

int main() {
    for (int T = read(); T; T--) {
        n = read(); k = read(); m = 0;
        for (int i = 0; i < n; i++) {
            a[i] = read(); b[i] = read();
            tb[m++] = a[i] - b[i]; tb[m++] = a[i]; tb[m++] = a[i] + b[i];
        }
        std::sort(tb, tb + m);
        m = std::unique(tb, tb + m) - tb;
        for (int i = 0; i < m; i++) {
            al[i].clear(); ap[i].clear(); ar[i].clear();
        }
        for (int i = 0; i < n; i++) {
            pl[i] = std::lower_bound(tb, tb + m, a[i] - b[i]) - tb;
            p[i] = std::lower_bound(tb, tb + m, a[i]) - tb;
            pr[i] = std::lower_bound(tb, tb + m, a[i] + b[i]) - tb;
            al[pl[i]].push_back(i); ap[p[i]].push_back(i); ar[pr[i]].push_back(i);
        }
        long long cl = 0, sl = 0, cr = 0, sr = 0;
        gl = -1;
        for (int j = 0; j < m; j++) {
            for (auto i : al[j]) {
                cl++; sl += tb[j];
            }
            for (auto i : ap[j]) {
                cl--; sl -= tb[pl[i]];
                cr++; sr += tb[pr[i]];
            }
            for (auto i : ar[j]) {
                cr--; sr -= tb[j];
            }
            ss[j] = cl * tb[j] - sl + sr - cr * tb[j];
            if (ss[j] > k) {
                if (gl == -1) { gl = j; }
                gr = j;
                pre[j] = ss[j] - tb[j];
            } else {
                pre[j] = -1e18;
            }
            if (j != 0) { pre[j] = std::max(pre[j - 1], pre[j]); }
        }
        for (int j = m - 1; j >= 0; j--) {
            if (ss[j] > k) {
                suf[j] = ss[j] + tb[j];
            } else {
                suf[j] = -1e18;
            }
            if (j != m - 1) { suf[j] = std::max(suf[j + 1], suf[j]); }
        }
        if (gl == -1) {
            for (int i = 0; i < n; i++) { putchar('1'); }
            printf("\n");
        } else {
            for (int i = 0; i < n; i++) {
                int ans = 1;
                if (tb[gl] <= a[i] - b[i] || tb[gr] >= a[i] + b[i]) {
                    ans = 0;
                } else if (pre[p[i]] + a[i] - b[i] > k || suf[p[i]] - a[i] - b[i] > k)  {
                    ans = 0;
                }
                printf("%d", ans);
            }
            printf("\n");
        }
    }
    return 0;
}